#include <stdio.h>
#include <string.h>
#include <windows.h>

int factorial(int n);

int arrangement(int n, int p);

int combination(int n, int p);

int permutation(int arr[], int length);

int total(int arr[], int length);

int main() {
    int n = combination(7, 4);
    
    printf("The combination of 7 choose 4 is %d\n", n);
    
    int arr[] = {1, 2, 3};
    int p = permutation(arr, 3);
    printf("The permutation of {1, 2, 3} is %d\n", p);

    return 0;
}

int factorial(int n) {
    int total = 1;
    for(int i = n; i > 0; i--) {
        total *= i;
    }
    return total;
}

int arrangement(int n, int p) {
    int total = 1;
    for(int i = 0; i < p; i++) {
        total *= (n - i);
    }
    return total;
}

int combination(int n, int p) {
    return arrangement(n, p) / factorial(p);
}

int permutation(int arr[], int length) {
    int divid = 1;
    for(int i = 0; i < length; i++) {
        divid *= factorial(arr[i]);
    }
    return factorial(total(arr, length)) / divid;
}

int total(int arr[], int length) {
    int n = 0;
    for(int i = 0; i < length; i++) {
        n += arr[i];
    }
    return n;
}
