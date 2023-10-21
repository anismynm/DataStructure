#include <stdio.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int max_size;
} Queue;

Queue CreateQueue(int max_size) {
    Queue queue;
    queue.max_size = max_size;
    queue.data = &queue.data[max_size];
    queue.front = 0;
    queue.rear = 0;
    return queue;
}

int FullQ(Queue* queue) {
    if ((queue -> rear + 1) % queue -> max_size == queue -> front) { // 강의 교안에는 Queue의 여분이 한 자리 있어도 포화 큐로 간주.
        return 1;
    }
    else {
        return 0;
    }
}

int EmptyQ(Queue* queue) {
    if (queue -> front == queue -> rear) { 
        return 1;
    }
    else {
        return 0;
    }
}

void AddQ(Queue* queue, int item) {
    if (FullQ(queue) == 1) {
        printf("** queue 공간 부족!\n");
        return;
    }
    queue -> rear = (queue -> rear + 1) % queue -> max_size;
    queue -> data[queue -> rear] = item;
}

void DeleteQ(Queue* queue) {
    if (EmptyQ(queue) == 1) {
        printf("** Delete할 데이터 없음!\n");
        return;
    }
    queue -> front = (queue -> front + 1) % queue -> max_size;
    queue -> data[queue -> front] = -1; // data가 없는 상태 : -1로 표현
}

void Show(Queue queue) {
    int start = (queue.front + 1) % queue.max_size;
    int end = queue.rear;
    printf("Queue 현황 : ");
    while (start != (end + 1) % queue.max_size) {
        if (queue.data[start] != -1) { // 해당 index에서의 데이터가 없지 않다면
            printf("%d ", queue.data[start]);
        }
        start = (start + 1) % queue.max_size;
    }
    printf("\n");
}

int main() {
    int max_size = 5;
    Queue queue = CreateQueue(max_size);
    DeleteQ(&queue); // 비어있어 Delete X.
    AddQ(&queue, 7);
    AddQ(&queue, 10);
    AddQ(&queue, 19);
    AddQ(&queue, 25);
    AddQ(&queue, 20); // 포화 큐라 Add X.
    DeleteQ(&queue);
    DeleteQ(&queue);
    AddQ(&queue, 35);
    AddQ(&queue, 17);
    Show(queue); // queue 상태 출력
}