#include <stdio.h>
#include <stdbool.h>

#define MAX_V 1001

int graph[MAX_V][MAX_V];
bool visited[MAX_V];
int maxDistance;

int dfs(int v, int distance) {
    visited[v] = true;
    int maxDist = 0;

    for (int i = 1; i <= graph[v][0]; i++) {
        int neighbor = graph[v][i];
        if (!visited[neighbor]) {
            int dist = dfs(neighbor, distance + 1);
            maxDist = (dist > maxDist) ? dist : maxDist;
        }
    }

    maxDistance = (distance > maxDistance) ? distance : maxDistance;

    return maxDist + 1;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 1; i <= V; i++) {
        graph[i][0] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][++graph[x][0]] = y;
        graph[y][++graph[y][0]] = x;
    }

    maxDistance = 0;
    dfs(1, 0);

    printf("%d\n", maxDistance);

    return 0;
}
