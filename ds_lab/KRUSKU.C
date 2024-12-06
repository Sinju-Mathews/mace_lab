#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, e, cost[20][20], parent[20], ne = 1, mincost = 0;

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, u, v, a, b, min;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);


	 // Initialize the cost matrix
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cost[i][j] = INT_MAX;

    // Input the edges and their weights
    printf("Enter the edges (u v) and their costs:\n");
    for (i = 1; i <= e; i++) {
        printf("Edge %d (u v): ", i);
        scanf("%d %d", &u, &v);
        printf("Cost of edge (%d, %d): ", u, v);
        scanf("%d", &cost[u][v]);
        cost[v][u] = cost[u][v]; // For undirected graph
    }

    // Initialize parent array
    for (i = 1; i <= n; i++)
        parent[i] = 0;

    // Kruskal's algorithm to find MST
    printf("Edges in the Minimum Spanning Tree:\n");
    while (ne < n) {
        for (i = 1, min = INT_MAX; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf(" edge %d: (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INT_MAX; // Mark edge as processed
    }

    printf("Minimum cost of spanning tree: %d\n", mincost);
    return 0;
}
