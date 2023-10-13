#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENT 100
#define _CRT_SECURE_NO_WARNINGS

struct student {
    char name[100];
    int num;
    int grade;
    int mid;
    int final;  
    int hw;
};

void SearchInfo(struct student* info, int student_cnt) {
    char name[100];
    printf("* 학생의 정보를 검색합니다.\n");
    printf("검색할 학생의 이름을 입력하시오 >> ");
    scanf("%s", name);
    int iCnt = 0;

    for (int i = 0; i < student_cnt; i ++) {
        if (strcmp(info[i].name, name) == 0) {
            iCnt++;
        }
    }

    if (iCnt == 0) {
        printf("학생 %s에 대한 정보가 존재하지않습니다!\n", name);
        return;
    }
    else {
        printf("\n학생 %s에 대한 검색결과 총 %d개.\n", name, iCnt);
        for (int i = 0; i < student_cnt; i ++) {
            if (strcmp(info[i].name, name) == 0) {
                printf("---------------------\n");
                printf("학번 : %d\n", info[i].num);
                printf("학년 : %d\n", info[i].grade);
                printf("중간점수 : %d\n", info[i].mid);
                printf("기말점수 : %d\n", info[i].final);
                printf("과제점수 : %d\n", info[i].hw);
                printf("---------------------\n");
            }
        }
        printf("* 학생 검색이 완료되었습니다.\n\n");
    }
}

void NewInfo(struct student* info, int *student_cnt) {
    char new_name[100];
    int new_num, new_grade, new_mid, new_final, new_hw;

    if (*student_cnt <= 100) {
        printf("* 학생의 정보를 신규 입력합니다.\n");
        printf("이름 >> ");
        scanf("%s", new_name);
        printf("학번 >> ");
        scanf("%d", &new_num);
        for (int i = 0; i < *student_cnt; i ++) {
            if (info[i].num == new_num) {
                printf("* ERROR : 학생의 정보가 이미 존재합니다!\n\n");
                return;
            }
        }
        printf("학년 >> ");
        scanf("%d", &new_grade);
        printf("중간고사 점수 >> ");
        scanf("%d", &new_mid);
        if (new_mid > 100) {
            printf("중간고사 점수는 100점을 넘을 수 없습니다. 다시 입력하세요.\n\n");
            return;
        }
        printf("기말고사 점수 >> ");
        scanf("%d", &new_final);
        if (new_final > 100) {
            printf("기말고사 점수는 100점을 넘을 수 없습니다. 다시 입력하세요.\n\n");
            return;
        }
        printf("과제 점수 >> ");
        scanf("%d", &new_hw);
        if (new_hw > 100) {
            printf("과제 점수는 100점을 넘을 수 없습니다. 다시 입력하세요.\n\n");
            return;
        }

        *student_cnt += 1;
        strcpy(info[*student_cnt - 1].name, new_name);
        info[*student_cnt - 1].num = new_num;
        info[*student_cnt - 1].grade = new_grade;
        info[*student_cnt - 1].mid = new_mid;
        info[*student_cnt - 1].final = new_final;
        info[*student_cnt - 1].hw = new_hw;
        printf("* 신규 입력이 완료되었습니다.\n");
        printf("총 학생 수는 %d명입니다.\n\n", *student_cnt);
    }
    else {
        printf("*ERROR : 학생의 수는 100명을 초과할 수 없습니다!\n\n");
    }
    
}

void DeleteInfo(struct student* info, int *student_cnt) {
    int DelNum;
    int DelIndex = -1;
    char confirm;

    if (*student_cnt > 0) {
        printf("* 학생의 정보를 삭제합니다.\n");
        printf("정보를 삭제할 학생의 학번을 입력하세요. >> ");
        scanf("%d", &DelNum);

        for (int i = 0; i < *student_cnt; i ++) {
            if (info[i].num == DelNum) {
                DelIndex = i;
            }
        }

        if (DelIndex == -1) {
            printf("* ERROR : 학생의 정보를 찾을 수 없습니다!\n\n");
        }
        else {
            printf("* 학생의 정보\n");
            printf("---------------------\n");
            printf("학번 : %d\n", info[DelIndex].num);
            printf("학년 : %d\n", info[DelIndex].grade);
            printf("중간점수 : %d\n", info[DelIndex].mid);
            printf("기말점수 : %d\n", info[DelIndex].final);
            printf("과제점수 : %d\n", info[DelIndex].hw);
            printf("---------------------\n");

            printf("학생의 정보를 삭제하시겠습니까? (삭제하려면 'y'를 입력.) >> ");
            getchar(); // 입력 버퍼 제거
            scanf("%c", &confirm);
            if (confirm == 'y') {
                for (int i = DelIndex; i < *student_cnt; i ++) {
                    info[i] = info[i + 1];
                }
                *student_cnt = *student_cnt - 1;
                printf("* 학생의 정보를 삭제하였습니다.\n");
                printf("총 학생 수는 %d명입니다.\n\n", *student_cnt);
            }
            else {
                printf("학생의 정보를 삭제하지 않습니다.\n\n");
                return;
            }
        }
    }
    else {
        printf("* ERROR : 학생정보가 존재하지않습니다!\n\n");
    }
}

void MidAverage(struct student* info, int student_cnt) {
    double TotalMid = 0;

    for (int i = 0; i < student_cnt; i ++) {
        TotalMid += info[i].mid;
    }
    double AvMid = TotalMid / student_cnt;

    printf("* %d명의 학생에 대한 중간고사 점수의 평균은 %.2f점입니다.\n\n", student_cnt, AvMid);
}

void FinalAverage(struct student* info, int student_cnt) {
    double TotalFinal = 0;

    for (int i = 0; i < student_cnt; i ++) {
        TotalFinal += info[i].final;
    }
    double AvFinal = TotalFinal / student_cnt;

    printf("* %d명의 학생에 대한 기말고사 점수의 평균은 %.2f점입니다.\n\n", student_cnt, AvFinal);
}

void HwAverage(struct student* info, int student_cnt) {
    double TotalHw = 0;

    for (int i = 0; i < student_cnt; i ++) {
        TotalHw += info[i].hw;
    }
    double AvHw = TotalHw / student_cnt;

    printf("* %d명의 학생에 대한 과제 점수의 평균은 %.2f점입니다.\n\n", student_cnt, AvHw);
}

void PrintRank(struct student* info, int student_cnt) {
    char file_name[100];
    int TotalScore[student_cnt];

    // 총점을 구한 후, BubbleSort로 구조체 배열 및 총점 배열 재정렬
    for (int i = 0; i < student_cnt; i ++) {
        TotalScore[i] = info[i].mid + info[i].final + info[i].hw;
    }
    for (int i = 0; i < student_cnt - 1; i ++) {
        for (int j = 0; j < student_cnt - 1 - i; j ++) {
            if (TotalScore[j] < TotalScore[j + 1]) {
                struct student tmp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = tmp;
                int temp = TotalScore[j];
                TotalScore[j] = TotalScore[j + 1];
                TotalScore[j + 1] = temp;
            }
        }
    }

    printf("* 학생들의 점수를 성적순으로 재정렬하고 파일을 만듭니다.\n");
    printf("생성할 파일의 이름을 입력하세요. >> ");
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        printf("* ERROR : 파일 생성 실패\n\n");
        return;
    }
    // 정렬된 학생정보 출력
    fprintf(file, "===============등수===============\n");
    for (int i = 0; i < student_cnt; i ++) {
        fprintf(file, "%d등 : %s(%d) 총점 : %d\n", i + 1, info[i].name, info[i].num, TotalScore[i]);
    }
    fprintf(file, "=================================\n");

    fclose(file);
    printf("* 정보를 등수에 따라 재정렬하고 파일 생성을 완료하였습니다.\n\n");
}

int main() {
    //동적 메모리 할당
    struct student* info = (struct student*)malloc(MAX_STUDENT * sizeof(struct student));

    // 초기 정보 생성
    int student_cnt = 10;
    char* init_name[10] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "AAA", "BBB"};
    int init_num[10] = {2020112736, 2022112345, 2023118421, 2019113942, 2021114823, 2020119432, 2018112944, 2020110909, 2023119212, 2017110921};
    int init_grade[10] = {2, 2, 1, 3, 2, 4, 4, 3, 1, 4};
    int init_mid[10] = {98, 78, 98, 95, 100, 74, 45, 66, 90, 75};
    int init_final[10] = {70, 23, 67, 68, 54, 87, 54, 58, 76, 45};
    int init_hw[10] = {100, 100, 100, 100, 90, 100, 70, 80, 100, 100};

    for (int i = 0; i < student_cnt; i ++) {
        strcpy(info[i].name, init_name[i]);
        info[i].num = init_num[i];
        info[i].grade = init_grade[i];
        info[i].mid = init_mid[i];
        info[i].final = init_final[i];
        info[i].hw = init_hw[i];
    }

    // Interface 구현
    int togo;
    printf("=======학생 성적 관리 프로그램=======\n");
    printf("1. 이름 검색\n");
    printf("2. 신규 입력\n");
    printf("3. 정보 삭제\n");
    printf("4. 중간고사 평균 출력\n");
    printf("5. 기말고사 평균 출력\n");
    printf("6. 과제점수 평균 출력\n");
    printf("7. 재정렬, 등수 출력\n");
    printf("8. 종료\n");
    printf("=====================================\n");
    while (1) {
        printf("메뉴를 입력하세요. (메뉴를 보려면 0을 입력.) >> ");
        scanf("%d", &togo);

        switch(togo) {
            case 0:
            printf("\n=======학생 성적 관리 프로그램=======\n");
            printf("1. 이름 검색\n");
            printf("2. 신규 입력\n");
            printf("3. 정보 삭제\n");
            printf("4. 중간고사 평균 출력\n");
            printf("5. 기말고사 평균 출력\n");
            printf("6. 과제점수 평균 출력\n");
            printf("7. 재정렬, 등수 출력\n");
            printf("8. 종료\n");
            printf("=====================================\n");
            break;

            case 1:
            SearchInfo(info, student_cnt);
            getchar();
            break;

            case 2:
            NewInfo(info, &student_cnt);
            getchar();
            break;

            case 3:
            DeleteInfo(info, &student_cnt);
            getchar();
            break;

            case 4:
            MidAverage(info, student_cnt);
            break;

            case 5:
            FinalAverage(info, student_cnt);
            break;

            case 6:
            HwAverage(info, student_cnt);
            break;

            case 7:
            PrintRank(info, student_cnt);
            getchar();
            break;

            case 8:
            printf("프로그램을 종료합니다.\n");
            free(info); // 할당받은 메모리 반환
            return 0;
            break;

            default:
            printf("*ERROR : 올바른 입력을 하세요.\n\n");
            getchar();
        }
    }
}