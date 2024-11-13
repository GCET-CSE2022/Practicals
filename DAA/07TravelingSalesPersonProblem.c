#include <stdio.h>
#include <stdbool.h>

#define INF 99999
#define N 4

int tsp(int graph[N][N], int start) {
    bool visited[N] = {false};
    int cost = 0, current = start;
    
    visited[current] = true;
    printf("Path: %d ", current);

    for (int i = 1; i < N; i++) {
        int nearest = -1;
        int minDistance = INF;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && graph[current][j] < minDistance) {
                minDistance = graph[current][j];
                nearest = j;
            }
        }

        visited[nearest] = true;
        cost += minDistance;
        current = nearest;
        printf("-> %d ", current);
    }

    cost += graph[current][start];
    printf("-> %d\n", start);

    return cost;
}

int main() {
    int graph[N][N] = {
        {INF, 20, 42, 35},
        {20, INF, 30, 34},
        {42, 30, INF, 12},
        {35, 34, 12, INF}
    };

    int start = 0;
    int minCost = tsp(graph, start);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}
 