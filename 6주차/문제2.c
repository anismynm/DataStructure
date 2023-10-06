#include <stdio.h>

int main() {
    int m, n, p;
    printf("<<m*n, n*p 행렬의 곱 계산하기>>\n");

    // 행렬의 크기 입력 받고 선언.
    printf("A의 행>> ");
    scanf("%d", &m);
    printf("A의 열 및 B의 행>> ");
    scanf("%d", &n);
    printf("B의 열>> ");
    scanf("%d", &p);
    int A[m][n], B[n][p], C[m][p];

    // 행렬 원소 입력 받기.
    printf("다음 %d개 행에 걸쳐서 행렬 A의 원소를 입력하시오.\n", m);
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\n다음 %d개 행에 걸쳐서 행렬 B의 원소를 입력하시오.\n", n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < p; j ++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // 행렬 곱 계산
    for (int i = 0; i < m; i ++) { // 이 for 문이 종료되면 C행렬 전체 완성
        for (int j = 0; j < p; j ++) { // 이 for 문이 종료되면 C행렬의 한 행 완성
            C[i][j] = 0; // C행렬 초기화
            for (int k = 0; k < n; k ++) { // 이 for 문이 종료되면 C행렬의 한 원소 완성
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    //행렬 곱 출력
    printf("\n<A행렬>\n");
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("<B행렬>\n");
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < p; j ++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n<C행렬>\n");
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < p; j ++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}