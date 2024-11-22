#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100001

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int color[MAX_VERTICES];

bool isBicolorable(int v, int c) {
    visited[v] = true;
    color[v] = c;

    for (int i = 1; i <= graph[v][0]; i++) {
        int neighbor = graph[v][i];
        if (!visited[neighbor]) {
            if (!isBicolorable(neighbor, c ^ 1))
                return false;
        } else if (color[neighbor] == color[v])
            return false;
    }

    return true;
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
    bool bicolorable = true;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            if (!isBicolorable(i, 0)) {
                bicolorable = false;
                break;
            }
        }
    }
    if (bicolorable)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
