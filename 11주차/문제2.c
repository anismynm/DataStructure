#include <stdio.h>
#include <stdlib.h>

typedef struct tree* tree_pointer;

typedef struct tree {
    int data;
    tree_pointer left_child;
    tree_pointer right_child;
} tree;

tree_pointer head = NULL;

void Insert(int key) {
    tree_pointer newTree = (tree_pointer)malloc(sizeof(tree));

    if (newTree == NULL) {
        printf("메모리 할당 오류!\n");
        return;
    }
    newTree -> data = key;
    newTree -> left_child = NULL;
    newTree -> right_child = NULL;

    if (head == NULL) { // 첫 삽입
        head = newTree;
        printf("삽입 완료\n");
        return;
    }

    tree_pointer p = head;
    while (1) {
        if (key == p -> data) { // 이미 key가 있을 때
            printf("%d을(를) 가진 트리가 이미 존재합니다!\n", key);
            return;
        }

        if (key < p -> data) {
            if (p -> left_child != NULL) {
                p = p -> left_child;
            }
            else {
                p -> left_child = newTree;
                printf("삽입 완료\n");
                return;
            }
        }
        else {
            if (p -> right_child != NULL) {
                p = p -> right_child;
            }
            else {
                p -> right_child = newTree;
                printf("삽입 완료\n");
                return;
            }
        }
    }
}

void Delete(int key) {
    tree_pointer p = head;
    tree_pointer parent = NULL;

    if (head == NULL) {
        printf("삭제할 트리가 없습니다!\n");
        return;
    }

    while (p) { 
        if (key == p -> data) {
            if (p -> left_child == NULL && p -> right_child == NULL) { // 자식이 없을 때
                if (parent == NULL) {
                    free(p);
                    head = NULL;
                }
                else {
                    if (parent -> left_child == p) {
                        parent -> left_child = NULL;
                    }
                    else {
                        parent -> right_child = NULL;
                    }
                    free(p);
                }
                printf("%d 삭제 완료 0\n", key);
                return;
            }
            else { // 자식이 있을 때
                if (p -> left_child != NULL && p -> right_child != NULL) { // 자식이 둘 다 있을 때
                    tree_pointer temp = p;
                    p = p -> right_child;
                    while (p -> left_child != NULL) {
                        parent = p;
                        p = p -> left_child;
                    }
                    temp -> data = p -> data;
                    
                    if (p -> right_child != NULL) {
                        if (parent -> left_child == p) {
                            parent -> left_child = p -> right_child;
                        }
                        else if (parent -> right_child == p) {
                            parent -> right_child = p -> right_child;
                        }
                    }
                    else {
                        parent -> left_child = NULL;
                    }

                    free(p);
                    printf("%d 삭제 완료 1\n", key);
                    return;
                }

                else if (p -> left_child == NULL && p -> right_child != NULL) { // 자식이 오른쪽만 있을 때
                    if (parent == NULL) {
                        head = p -> right_child;
                    }
                    else {
                        if (parent -> left_child == p) {
                            parent -> left_child = p -> right_child;
                        }
                        else {
                            parent -> right_child = p -> right_child;
                        }
                    }
                }

                else { // 자식이 왼쪽만 있을 때
                    if (parent == NULL) {
                        head = p -> left_child;
                    }
                    else {
                        if (parent -> left_child == p) {
                            parent -> left_child = p -> left_child;
                        }
                        else {
                            parent -> right_child = p -> left_child;
                        }
                    }
                }

                free(p);
                printf("%d 삭제 완료 2\n", key);
                return;
            }
        }

        parent = p;

        if (key < p -> data) {
            p = p -> left_child;
        } 
        else {
            p = p -> right_child;
        }
    }

    printf("삭제할 트리를 찾을 수 없습니다!\n");
    return;         
}

void Search(int key) {
    tree_pointer p = head;
    tree_pointer parent = NULL;
    while (p != NULL) {
        if (key == p -> data) {
            if (parent != NULL) {
                printf("%d is exist. (parent : %d)\n", p -> data, parent -> data);
            }
            else {
                printf("%d is exist. (parent : NONE)\n", p -> data);
            }
            return;
        }
        else if (key < p -> data) {
            parent = p;
            p = p -> left_child;
        }
        else {
            parent = p;
            p = p -> right_child;
        }
    }
    printf("%d is not exist.\n", key);
}

void Print(tree_pointer p, int level, int c) { 
    if (p == NULL) {
        return;
    }
    int interval = 6;

    Print(p -> right_child, level + 1, -1);

    if (c == 1) {
        for (int i = 0; i < level * interval - 1; i ++) {
            printf(" ");
        }
        printf("\\\n");
    }

    for (int i = 0; i < level * interval; i++) {
        printf(" ");
    }
    printf("%d\n", p -> data);

    if (c == -1) {
        for (int i = 0; i < level * interval - 1; i ++) {
            printf(" ");
        }
        printf("/\n");
    }

    Print(p -> left_child, level + 1, 1);
}

int main() {
    // 임의로 만든 트리.
    Insert(40);
    Insert(20);
    Insert(60);
    Insert(10);
    Insert(30);
    Insert(50);
    Insert(70);
    Insert(5);
    Insert(15);
    Insert(25);
    Insert(45);
    Insert(55);
    Insert(80);
    Insert(90);
    
    int select, key;

    while (1) {
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 검색\n");
        printf("4. 출력\n");
        printf("5. 종료\n");
        printf(">> ");
        scanf("%d", &select);

        switch (select) {
            case 1:
            printf("key 입력 >> ");
            rewind(stdin);
            scanf("%d", &key);
            Insert(key);
            break;

            case 2:
            printf("삭제할 key 입력 >> ");
            rewind(stdin);
            scanf("%d", &key);
            Delete(key);
            break;

            case 3:
            printf("검색할 key 입력 >> ");
            rewind(stdin);
            scanf("%d", &key);
            Search(key);
            break;

            case 4:
            Print(head, 0, 0);
            printf("\n");
            break;

            case 5:
            printf("종료\n");
            return 0;

            default:
            printf("잘못 입력\n");
            break;
        }
    }
}