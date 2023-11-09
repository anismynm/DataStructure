#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct list_node *list_pointer;
typedef struct list_node {
    char name[50];
    double score;
    list_pointer llink; 
    list_pointer rlink;
} list_node;

list_pointer head = NULL;

void Insert() {
    list_pointer newStudent = (list_pointer)malloc(sizeof(list_node));
    if (newStudent == NULL) {
        printf("메모리 할당 오류!\n");
        return;
    }
    
    printf("학생의 이름을 입력하시오. >> ");
    rewind(stdin); // 입력 버퍼 제거
    scanf("%s", newStudent -> name);
    printf("학생의 성적을 입력하시오. >> ");
    rewind(stdin);
    scanf("%lf", &newStudent -> score);

    newStudent -> llink = NULL;
    newStudent -> rlink = NULL;

    if (head == NULL) {
        head = newStudent;
        printf("학생의 정보가 추가되었습니다.\n");
        return;
    }
    else { // Linked List에 점수 높은 순으로 삽입
        // 입력 받은 점수가 1등일 때
        if (newStudent -> score >= head -> score) {
            head -> llink = newStudent;
            newStudent -> rlink = head;
            head = newStudent;
            printf("학생의 정보가 추가되었습니다.\n");
            return;
        }
        // 1등이 아닌경우
        list_pointer p = head;
        while (p != NULL) {
            if (p -> rlink == NULL) { // 꼴찌일 때
                p -> rlink = newStudent;
                newStudent -> llink = p;
                printf("학생의 정보가 추가되었습니다.\n");
                return;
            }
            else { // 꼴찌가 아닐 때
                if (newStudent -> score >= p -> rlink -> score) {
                    newStudent -> rlink = p -> rlink;
                    newStudent -> llink = p;
                    p -> rlink -> llink = newStudent;
                    p -> rlink = newStudent;
                    printf("학생의 정보가 추가되었습니다.\n");
                    return;
                }
                else {
                    p = p -> rlink;
                }
            }
        }
    }
}

void Delete() {
    if (head == NULL) {
        printf("학생의 정보가 존재하지 않습니다!\n");
        return;
    }

    char NameForSearch[50];
    printf("삭제할 학생의 이름을 입력하시오. >> ");
    rewind(stdin);
    scanf("%s", NameForSearch);

    list_pointer p = head;
    while (p != NULL) {
        if (strcmp(p -> name, NameForSearch) == 0) {
            if (p -> llink == NULL) {
                head = p -> rlink;
                if (head != NULL) {
                    head -> llink = NULL;
                }
            }
            else {
                p -> llink -> rlink = p -> rlink;
                if (p -> rlink != NULL) {
                    p -> rlink -> llink = p -> llink;
                }
            }
            free(p);
            printf("학생의 정보가 삭제되었습니다.\n");
            return;
        }
        else {
            p = p -> rlink;
        }
    }
    printf("검색 결과, 해당하는 학생의 정보가 존재하지 않습니다.\n");
    return;
}

void Search() {
    if (head == NULL) {
        printf("학생의 정보가 존재하지 않습니다!\n");
        return;
    }

    char NameForSearch[50];
    printf("검색할 학생의 이름을 입력하시오. >> ");
    rewind(stdin);
    scanf("%s", NameForSearch);

    list_pointer p = head;
    int rank = 1;
    while (p != NULL) {
        if (strcmp(p -> name, NameForSearch) == 0) {
            printf("%s 학생의 점수는 %.1f점이고 %d등입니다.\n", p -> name, p -> score, rank);
            return;
        }
        else {
            p = p -> rlink;
            rank++;
        }
    }
    printf("검색 결과, 해당하는 학생의 정보가 존재하지 않습니다.\n");
    return;
}

int main() {
    int iSelect;
    do {
        printf("┌──────────────────────────────────┐\n");
        printf("│ 자료구조 시험 성적 관리 프로그램 │\n");
        printf("│ 1. 학생 성적 입력                │\n");
        printf("│ 2. 학생 정보 제거                │\n");
        printf("│ 3. 학생 성적 검색                │\n");
        printf("│ 4. 종료                          │\n");
        printf("└──────────────────────────────────┘\n");
        printf("메뉴 선택 >> ");
        rewind(stdin);
        scanf("%d", &iSelect);
        switch(iSelect) {
            case 1:
            Insert();
            break;
            case 2:
            Delete();
            break;
            case 3:
            Search();
            break;
            case 4:
            printf("프로그램을 종료합니다.\n");
            list_pointer p = head;
            while (p != NULL) {
                list_pointer temp = p -> rlink;
                free(p);
                p = temp;
            } // 프로그램 종료 전 할당받은 메모리 모두 반환.
            return 0;
            break;
            default:
            printf("올바른 메뉴를 선택하세요.\n");
            break;
        }
    } while (iSelect != 4);
}