/* 
Name: Aswin K U 
Roll No: CS06
Date: 01/10/2026

Experiment No : 14
 
Heading:  Graphs
 
AIM: Implementation  of  graphs  and  graph  traversals


ALGORITHM

1. Start.

2. Read the number of vertices and initialize the adjacency matrix with 0.

3. Read the number of edges.

4. For each edge, read the source and destination vertices and set the corresponding adjacency matrix elements to 1.

5. Read the starting vertex.

6. Perform BFS:

   a. Initialize all vertices as unvisited.

   b. Mark the starting vertex as visited and insert it into the queue.

   c. Remove a vertex from the queue and display it.

   d. Visit all adjacent unvisited vertices, mark them as visited, and insert them into the queue.

   e. Repeat until the queue becomes empty.

7. Perform DFS:

   a. Initialize all vertices as unvisited.

   b. Mark the current vertex as visited and display it.

   c. Visit each adjacent unvisited vertex recursively.

   d. Repeat until all reachable vertices are visited.

8. Display the BFS and DFS traversals.

9. Stop.

SOURCE CODE
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int vertices;
    int adj[MAX][MAX];
};

void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;
}

void BFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->vertices; i++) {
        if (g->adj[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(struct Graph* g, int startVertex) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFSUtil(g, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph g;
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1) return 0;
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1) return 0;

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Enter start vertex for traversal: ");
    if (scanf("%d", &start) != 1) return 0;

    BFS(&g, start);
    DFS(&g, start);

    return 0;
}


/*
OUTPUT

Enter number of vertices: 4

Enter number of edges: 4
Enter edge (source destination): 0 1
Enter edge (source destination): 0 2
Enter edge (source destination): 1 3
Enter edge (source destination): 2 3

Enter start vertex for traversal: 0
BFS Traversal: 0 1 2 3
DFS Traversal: 0 1 3 2

*/