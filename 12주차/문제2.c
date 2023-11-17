#include <stdio.h>
#define N 6

int min(int a, int b) {
    return (a < b) ? a : b;
}

int adj[N][N] = {{0, 50, 10, 999, 65, 999},
                 {999, 0, 15, 999, 10, 999},
                 {20, 999, 0, 15, 999, 999},
                 {999, 20, 999, 0, 35, 999},
                 {999, 999, 999, 30, 0, 999},
                 {999, 999, 999, 3, 999, 0}};

int main() {
    int min_dist[N];

    for (int i = 0; i < N; i ++) {
        int found[N] = {0, };
        int dist[N] = adj[i];
        

    }
}