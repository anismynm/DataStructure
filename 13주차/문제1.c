#include <stdio.h>

void bubble_sort(int list[], int n) {
    int end_flag = 1;

    for (int i = n - 1; end_flag > 0; i --) {
        end_flag = 0;
        for (int j = 0; j < i; j ++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                end_flag++;
            }
        }

        if (end_flag > 0) {
            for (int j = 0; j < n; j ++) {
                printf("%d ", list[j]);
            }
            printf("\n");
        }
    }
}

void insertion_sort(int list[], int n) {
    for (int i = 1; i < n; i ++) {
        int j;
        int insert = list[i];
        
        for (j = i - 1; j >= 0 && list[j] > insert; j --) {
            list[j + 1] = list[j];
        }
        list[j + 1] = insert;

        for (int k = 0; k <= i; k ++) {
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}

int partition(int list[], int left, int right) {
    int i = left;
    int j = right + 1;
    int pivot = list[left];

    while (i < j) {
        while (list[++i] < pivot);
        while (list[--j] > pivot);
        if (i < j) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    int temp = list[left];
    list[left] = list[j];
    list[j] = temp;

    return j;
}

void quick_sort(int list[], int left, int right) {
    if (left < right) {
        for (int i = 0; i < 10; i ++) {
            printf("%d ", list[i]);
        }
        printf("left : %d, right : %d\n", left, right);
        
        int mid = partition(list, left, right);

        quick_sort(list, left, mid - 1);
        quick_sort(list, mid + 1, right);
    }
}

void merge(int list[], int left, int mid, int right) {  
    int sorted_list[10];
    int i = left;
    int j = mid + 1;
    int index = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            sorted_list[index++] = list[i++];
        }
        else {
            sorted_list[index++] = list[j++];
        }
    }

    if (i > mid) {
        for (int k = j; k <= right; k ++) {
            sorted_list[index++] = list[k];
        }
    }
    else {
        for (int k = i; k <= mid; k ++) {
            sorted_list[index++] = list[k];
        }
    }

    for (int p = left; p <= right; p ++) {
        list[p] = sorted_list[p];
    }   
}

void merge_sort(int list[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);

        merge(list, left, mid, right);

        for (int i = left; i <= right; i ++) {
            printf("%d ", list[i]);
        }
        printf("\n-> left : %d, right : %d\n", left, right);
    }
}

int main() {
    int arr[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    int n = 10;
    int menu;
    
    printf("input >> ");
    scanf("%d", &menu);
    switch (menu) {
        case 0:
        return 0;
        break;

        case 1:
        printf("== bubble sort ==\n");
        bubble_sort(arr, n);
        break;

        case 2:
        printf("== insertion sort ==\n");
        insertion_sort(arr, n);
        break;

        case 3:
        printf("== quick sort ==\n");
        quick_sort(arr, 0, n - 1);
        break;

        case 4:
        printf("== merge sort ==\n");
        merge_sort(arr, 0, n - 1);
        break;

        default:
        break;
    }
}