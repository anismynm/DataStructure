#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max_size;
    int top;
    int* data;
} Stack;

Stack CreateStack(int max_size) {
    Stack stack;
    stack.max_size = max_size;
    stack.data = &stack.data[max_size]; // "stack.data[max_size];"로 선언만 할 경우 warning: expression result unused [-Wunused-value] 발생.
    stack.top = -1;
    return stack;
}

int IsEmpty(Stack* stack) {
    if (stack -> top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int IsFull(Stack* stack) {
    if (stack -> top >= stack -> max_size - 1) {
        return 1;
    } 
    else {
        return 0;
    }
}

void Push(Stack* stack, int item) {
    if (IsFull(stack) == 1) {
        printf("** Stack 공간 부족!\n");
        return;
    }
    stack -> data[++stack -> top] = item;
}

void Pop(Stack* stack) {
    if (IsEmpty(stack) == 1) {
        printf("** Pop할 데이터 없음!\n");
        return;
    }
    stack -> data[stack -> top--] = -1; // data가 없는 상태 : -1로 표현
}

void Show(Stack stack) {
    printf("Stack 현황: ");
    for (int i = 0; i <= stack.top; i ++) {
        printf("%d, ",stack.data[i]);
    }
    printf("\n");
}

int main() {
    int max_size = 5;
    Stack stack = CreateStack(max_size);
    Pop(&stack); // 비어있어 Pop X.
    Push(&stack, 7);
    Push(&stack, 3);
    Push(&stack, 5);
    Push(&stack, 8);
    Push(&stack, 15);
    Push(&stack, 20); // 포화 상태라 Push X.
    Pop(&stack);
    Push(&stack, 35);
    Show(stack);
}
