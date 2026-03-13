#include "graph.h"

struct Graph* createGraph(int n) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->numAirports = n;
    g->adjList = (struct Edge**)malloc(n * sizeof(struct Edge*));
    for (int i = 0; i < n; i++) g->adjList[i] = NULL;
    return g;
}

void addEdge(struct Graph* g, int src, int dest, int cost, int time) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->destination = dest;
    newEdge->cost = cost;
    newEdge->time = time;
    newEdge->next = g->adjList[src];
    g->adjList[src] = newEdge;
}

int getAirportIndex(struct Graph* g, char* name) {
    for (int i = 0; i < g->numAirports; i++)
        if (strcmp(g->airportNames[i], name) == 0) return i;
    return -1;
}

void representAirports(struct Graph* g) {
    printf("\nAirports and their connections:\n");
    for (int i = 0; i < g->numAirports; i++) {
        printf("%s -> ", g->airportNames[i]);
        struct Edge* temp = g->adjList[i];
        while (temp) {
            printf("%s(cost:%d,time:%d) ",
                   g->airportNames[temp->destination],
                   temp->cost,
                   temp->time);
            temp = temp->next;
        }
        printf("\n");
    }
}
