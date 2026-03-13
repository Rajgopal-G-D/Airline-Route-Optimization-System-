#include "graph.h"

int minIndex(int dist[], int visited[], int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min) min = dist[i], idx = i;
    return idx;
}

void dijkstra(struct Graph* g, int src, int dest, int useTime) {
    int n = g->numAirports;
    int dist[100], visited[100], parent[100];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX, visited[i] = 0, parent[i] = -1;
    dist[src] = 0;

    int queue[100], front = 0, rear = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = -1, minVal = INT_MAX;
        for (int i = 0; i < rear; i++)
            if (!visited[queue[i]] && dist[queue[i]] < minVal)
                minVal = dist[queue[i]], u = queue[i];
        if (u == -1) break;
        visited[u] = 1;

        struct Edge* temp = g->adjList[u];
        while (temp) {
            int v = temp->destination;
            int weight = useTime ? temp->time : temp->cost;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (dist[dest] == INT_MAX) {
        printf("No path found between %s and %s\n", g->airportNames[src], g->airportNames[dest]);
        return;
    }

    printf("\n%s shortest path from %s to %s:\n",
           useTime ? "Fastest" : "Cheapest",
           g->airportNames[src], g->airportNames[dest]);

    printf("Total %s: %d\n", useTime ? "Time" : "Cost", dist[dest]);

    int path[100], count = 0;
    for (int v = dest; v != -1; v = parent[v]) path[count++] = v;

    printf("Path: ");
    for (int i = count - 1; i >= 0; i--)
        printf("%s%s", g->airportNames[path[i]], i ? " -> " : "\n");
}

void findCheapestPath(struct Graph* g, int src, int dest) {
    dijkstra(g, src, dest, 0);
}

void findFastestPath(struct Graph* g, int src, int dest) {
    dijkstra(g, src, dest, 1);
}
