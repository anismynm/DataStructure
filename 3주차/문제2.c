#include <stdio.h>

// 최대공약수
int gcd(int a, int b) {
    int r;

    // a가 더 큰 수가 되게 처리
    if (a < b) { 
        int sth = a;
        a = b;
        b = sth;
    }

    // gcd 계산 (a가 더 큰 수가 되어야 함)
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// 공약수의 개수
void com_fac(int a, int b) {
    int fac_cnt = 0;
    if (a > 1 && a < 10000 && b > 1 && b < 10000) {
        int iNum = gcd(a, b);

        // 최대공약수 'iNum'의 약수의 개수 = 공약수의 개수
        for (int i = 1; i <= iNum; i++) {
            if (iNum % i == 0) {
                fac_cnt++;
            }
        }
        printf("%d\n", fac_cnt);
    }
}

// 공배수의 개수
void com_mul(int a, int b) {
    int mul_cnt = 0;
    if (a > 1 && a < 10000 && b > 1 && b < 10000) {
        int iNum = gcd(a, b);

        // 최대공약수와 두 숫자의 나머지 인수들의 곱 = 공배수
        int arg_a = a / iNum;
        int arg_b = b / iNum;
        int result = iNum * arg_a * arg_b;
        
        // 100만보다 작은 공배수의 배수 = 공배수의 개수
        for (int i = 1; result * i <= 1000000; i ++) {
            mul_cnt++;
        }
        printf("%d\n", mul_cnt);
    }
}

int main() {
    com_fac(175, 465);
    com_mul(175, 465);
    return 0;
}