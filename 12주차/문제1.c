#include <stdio.h>
#include <stdlib.h>
#define N 4

int adj[N][N] = { {0, 1, 1, 0}, 
                  {1, 0, 1, 1},
                  {1, 1, 0, 1},
                  {0, 1, 1, 0}};

typedef struct grape* grape_pointer;

typedef struct grape {
    int vertex;
    grape_pointer link;
} grape;

void Insert(grape_pointer vert, int key) {
    grape_pointer newVert = (grape_pointer)malloc(sizeof(grape));
    newVert -> vertex = key;
    newVert -> link = NULL;
    grape_pointer p = vert;
    while (p -> link != NULL) {
        p = p -> link;
    }
    p -> link = newVert;
}

int main() {
    grape_pointer vert[N];
    for (int i = 0; i < N; i ++) {
        vert[i] = (grape_pointer)malloc(sizeof(grape));
        vert[i] -> vertex = i;
        vert[i] -> link = NULL;
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (adj[i][j] == 1) {
                Insert(vert[i], j);
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        printf("정점 %d의 인접리스트 -> ", i);
        grape_pointer p = vert[i];
        p = p -> link;
        while (p != NULL) {
            printf("%d -> ", p -> vertex);
            p = p -> link;
        }
        printf("\n");
    }

    for (int i = 0; i < N; i ++) {
        grape_pointer p = vert[i];
        while (p != NULL) {
            grape_pointer temp = p;
            p = p -> link;
            free(temp);
        }
    }
}