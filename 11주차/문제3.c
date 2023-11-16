#include <stdio.h>
#include <math.h>
#define MAX_ELEMENT 10

int heap[MAX_ELEMENT] = {0, }; // Heap을 통해 정렬할 배열 0으로 초기화
int nodeNum = 0;

void InsertHeap(int data) {
    int index = ++nodeNum;
    while ((index != 1) && (data > heap[index / 2])) { // 처음 넣는거 아니고 부모 노드보다 삽입하려는게 클 경우
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = data;
}

int DeleteHeap() {
    int max = heap[1];
    int temp = heap[nodeNum]; // 마지막 원소를 temp에 할당(delete 할거니까)
    heap[nodeNum--] = 0; // 옮겨 갈 마지막 원소 제거(0으로 초기화)해주고 원소 개수 -1
    int p = 1;
    int c = 2;
    while (c <= nodeNum) {
        if ((c < nodeNum) && (heap[c] < heap[c + 1])) {
            c++;
        }
        if (temp >= heap[c]) {
            break;
        }
        heap[p] = heap[c];
        p = c;
        c *= 2;
    }
    heap[p] = temp;

    return max;
}   

void SearchHeap(int key, int index) {
    if (key < heap[index]) {
        if (heap[2 * index] != 0) {
            SearchHeap(key, 2 * index);
        }
        if (heap[2 * index + 1] != 0) {
            SearchHeap(key, 2 * index + 1); 
        }
    }
    else if (key == heap[index]) {
        printf("%d is in index %d.\n", heap[index], index);
    }
    
    if (index == nodeNum) {
        printf("%d is not exist.\n", key);
    }
}

void PrintHeap() {
    int height = (int)log2(nodeNum) + 1; // complete BT 특성으로 높이 구하기
    for (int i = 1; i <= height; i++) {
        int start = 1 << (i - 1); // 2^(i-1)
        int end = 1 << i; // 2^i
        for (int j = start; j < end; j++) {
            if (j <= nodeNum) {
                printf("%d ", heap[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int arr[5] = {2, 4, 6, 8, 10}; // 임의의 배열
    for (int i = 0; i < 5; i ++) {
        InsertHeap(arr[i]);
    }
    DeleteHeap();
    printf("== tree == \n");
    PrintHeap();
    printf("\n");
    
}