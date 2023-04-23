// Online C compiler to run C program online
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void something();

int main() {
    // Write C code here
    printf("Hello world");

    MessageBox(NULL, "Hello world", "error one 03023", 0);


    return 0;
}

void something() {
    for( int i = 0; i < 1000000; i++) {
        printf("%d\n", i);
    }
}