#include <stdio.h>
#include <stdlib.h>

typedef struct list_node *list_pointer;
typedef struct list_node {
    int data;
    list_pointer llink; 
    list_pointer rlink;
} list_node;

list_node* head;

list_node* CreateNode() { // 노드만 생성 (노드 속 데이터는 지정 X)
    list_node* new;
    new = (list_node*)malloc(sizeof(list_node));
    new -> data = 10;
    new -> link = NULL;
    return new;
}

list_node* CreateTwoNodes() {
    list_node* new1;
    list_node* new2;
    new1 = (list_node*)malloc(sizeof(list_node));
    new2 = (list_node*)malloc(sizeof(list_node));

    new1 -> data = 0;
    new1 -> link = new2;
    new2 -> data = 0;
    new2 -> link = NULL;

    return new1;
}

void Insert(list_node* p, list_node* new, int data) { // p node 뒤에 new node 삽입
    if(p) {
        new -> link = p -> link;
        p -> link = new;
        new -> data = data;
    }
    else { // 리스트의 가장 앞에 삽입
        new -> link = head;
        head = new;
    }
}

void Delete(list_node* p, list_node* node) {
    if (p) {
        p -> link = node -> link;
    }
    else {
        head = head -> link;
    }
    free(node);
}

list_node* Search(list_node* head, int data) {
    while(head) {
        if (head -> data == data) {
            return head;
        }
        head = head -> link;
    }
    return NULL;
}

void Print(list_node* head) {
    list_node* p = head;
    while(p != NULL) {
        printf("%d ", p -> data);
        p = p -> link;
    }
    printf("\n");
}

int main() {
    printf("=====Doubly Linked List=====\n");
    
}