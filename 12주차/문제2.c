#include <stdio.h>
#define N 6
#define START_INDEX 5

int adj[N][N] = {{0, 999, 25, 15, 999, 999},
                 {15, 0, 999, 999, 10, 999},
                 {10, 50, 0, 999, 65, 999},
                 {999, 20, 999, 0, 35, 999},
                 {999, 999, 999, 30, 0, 999},
                 {999, 999, 999, 3, 999, 0}};

int main() {
    int dist[N];
    int found[N];

    int index = START_INDEX; // 시작 위치
    for (int i = 0; i < N; i ++) { // 최단거리 배열, 찾은 정점에 대한 배열 초기화
        dist[i] = adj[START_INDEX][i];
        found[i] = 0;
    }

    for (int i = 0; i < N; i ++) {
        int min_dist = 999;
        int min_index = 0; // 현재 위치에서 최단 거리의 인덱스

        for (int j = 0; j < N; j ++) { // 현재 위치에서 최단 거리 구하기 (단, 이미 found한 곳 제외)
            if (found[j] == 0 && adj[index][j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        index = min_index;
        found[index] = 1; // 현재 장소까지의 최단거리 found

        for (int i = 0; i < N; i ++) {
            if (dist[index] + adj[index][i] < dist[i]) { 
                dist[i] = dist[index] + adj[index][i];
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        printf("v%d에서 v%d까지의 최단거리 : %d\n", START_INDEX, i, dist[i]);
    }
}