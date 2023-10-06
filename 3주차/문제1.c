#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void func(int a, int b) {
    if (a > 1 && a < 10000 && b > 1 && b < 10000) {
        int iDiv;
        for (int i = 1; i < 10000; i *= 10) {
            iDiv = (b / i) % 10;
            if (iDiv != 0){ 
                printf("%d\n", a * iDiv);
            }
        }
        printf("%d\n", a * b);
    }
}

int main() {
    func(32, 33);
    return 0;
}