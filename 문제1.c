#include <stdio.h>
#include <math.h> 

typedef struct {
    double x;
    double y;
    double r;
} Circle;

typedef struct {
    double x;
    double y;
} Point;

void CircleAndPoint(double x, double y, double r, double p, double q) {
    if ((p-x)*(p-x) + (q-y)*(q-y) == r*r) {
        printf("원 위에 있습니다.\n");
    }
    else if ((p-x)*(p-x) + (q-y)*(q-y) > r*r) {
        printf("원 밖에 있습니다.\n");
    }
    else {
        printf("원 안에 있습니다.\n");
    }
}

void CircleAndCircle(double x1, double y1, double r1, double x2, double y2, double r2) {
    double point_dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if (point_dist == 0) { // 두 원의 중심이 일치
        if (r1 == r2) {
            printf("두 원은 일치합니다.\n");
        }
        else if (r1 < r2) {
            printf("원 A는 원 B안에 있습니다.\n");
        }
        else {
            printf("원 B는 원 A안에 있습니다.\n");
        }
    }

    else { // 두 원의 중심이 일치X
        if (point_dist == r1 + r2) { // 외접
            printf("두 원은 한 점에서 일치합니다.\n");
        }
        else if (point_dist > r1 + r2) {
            printf("두 원은 만나지 않습니다.\n");
        }
        else { // point_dist < r1 + r2
            if (r1 > r2) {
                if ((r1 - r2) < point_dist) {
                    printf("두 원은 두 점에서 일치합니다.\n");
                }
                else if ((r1 - r2) == point_dist) {
                    printf("원 B는 원 A안에 있고 한 점에서 일치합니다.\n");
                }
                else { // (r1 - r2) > point_dist
                    printf("원 B는 원 A안에 있습니다.\n");
                }
            }
            else if (r1 < r2) {
                if ((r2 - r1) < point_dist) {
                    printf("두 원은 두 점에서 일치합니다.\n");
                }
                else if ((r2 - r1) == point_dist) {
                    printf("원 A는 원 B안에 있고 한 점에서 일치합니다.\n");
                }
                else { // (r1 - r2) > point_dist
                    printf("원 A는 원 B안에 있습니다.\n");
                }
            }
            else { // r1 == r2
                printf("두 원은 두 점에서 일치합니다.\n");
            }
        }
    }
}

int main() {
    Circle cInput;
    Circle cInput2;
    Point pInput;

    printf("원 A의 중심의 좌표와 반지름을 입력하시오.>> ");
    scanf("%lf %lf %lf", &cInput.x, &cInput.y, &cInput.r);

    printf("판별할 점을 입력하시오.>> ");
    scanf("%lf %lf", &pInput.x, &pInput.y);

    CircleAndPoint(cInput.x, cInput.y, cInput.r, pInput.x, pInput.y);

    printf("원 B의 중심의 좌표와 반지름을 입력하시오.>> ");
    scanf("%lf %lf %lf", &cInput2.x, &cInput2.y, &cInput2.r);

    CircleAndCircle(cInput.x, cInput.y, cInput.r, cInput2.x, cInput2.y, cInput2.r);

    return 0;
}