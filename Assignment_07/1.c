#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTICES 100000

struct Node {
    int vertex;
    struct Node* next;
};


struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjacencyList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

int bfs(struct Node* adjacencyList[], int V, int S, int D) {
    int distance[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};

    for (int i = 1; i <= V; i++) {
        distance[i] = -1;
    }

    distance[S] = 0;
    visited[S] = true;

    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;
    queue[rear++] = S;
    while (front < rear) {
        int u = queue[front++];

        struct Node* temp = adjacencyList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                distance[v] = distance[u] + 1;
                visited[v] = true;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    return distance[D];
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    struct Node* adjacencyList[MAX_VERTICES];
    for (int i = 1; i <= V; i++) {
        adjacencyList[i] = NULL;
    }

    for (int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(adjacencyList, x, y);
    }

    int S, D;
    scanf("%d %d", &S, &D);

    int distance = bfs(adjacencyList, V, S, D);
    if (distance == -1) {
        printf("INF\n");
    } else {
        printf("%d\n", distance);
    }

    return 0;
}
