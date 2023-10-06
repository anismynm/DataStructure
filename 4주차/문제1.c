#include <stdio.h>

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int array[] = {1, 2, 3, 4};
    int size = sizeof(array)/sizeof(int); // 배열의 크기를 직접 받아 요소의 갯수를 구한 후 함수에 전달한다.
    print_arr(array, size);
    return 0;
}