#include <stdio.h>

int func(int n, int* arr) {
    if (n < 3) {
        return arr[n];
    }
    else {
        for (int i = 3; i <= n; i ++) {
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
        }
        return arr[n];
    }
}
int recursion(int n, int* arr) {
    if (n < 3) {
        return arr[n];
    }
    else {
        arr[n] = recursion(n-1, arr) + recursion(n-2, arr) + recursion(n-3, arr);
        return arr[n];
    }
}

int main() {
    int* array;
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    int result0 = func(2, array);
    int result1 = recursion(2, array);
    printf("%d\n", result0);
    printf("%d\n", result1);
    
    return 0;
}