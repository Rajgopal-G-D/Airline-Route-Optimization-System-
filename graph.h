#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge {
    int destination;
    int cost;
    int time;
    struct Edge* next;
};

struct Graph {
    int numAirports;
    char airportNames[100][50];
    struct Edge** adjList;
};

// Core existing functions
struct Graph* createGraph(int n);
void addEdge(struct Graph* g, int src, int dest, int cost, int time);
int getAirportIndex(struct Graph* g, char* name);
void representAirports(struct Graph* g);
void findCheapestPath(struct Graph* g, int src, int dest);
void findFastestPath(struct Graph* g, int src, int dest);
void optimizeMultiHopFlights(struct Graph* g, int src, int dest);

// NEW FUNCTIONS (added without altering existing ones)
void storeFlights(struct Graph* g);
void handleLayovers(struct Graph* g, int src, int dest);

#endif
