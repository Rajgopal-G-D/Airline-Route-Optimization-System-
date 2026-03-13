#include "graph.h"

void optimizeMultiHopFlights(struct Graph* g, int src, int dest) {
    printf("\nOptimizing multi-hop route (via Dijkstra logic):\n");
    findCheapestPath(g, src, dest);
}

// ---------------------------------------------
// NEW FUNCTION 1: store all flights
// ---------------------------------------------
void storeFlights(struct Graph* g) {
    printf("\n--- Stored Flights List ---\n");

    for (int i = 0; i < g->numAirports; i++) {
        struct Edge* temp = g->adjList[i];
        while (temp) {
            printf("%s -> %s | Cost: %d | Time: %d\n",
                   g->airportNames[i],
                   g->airportNames[temp->destination],
                   temp->cost,
                   temp->time);

            temp = temp->next;
        }
    }
}

// ---------------------------------------------
// NEW FUNCTION 2: find layover options
// ---------------------------------------------
void handleLayovers(struct Graph* g, int src, int dest) {
    printf("\n--- Checking Layover Options from %s to %s ---\n",
           g->airportNames[src], g->airportNames[dest]);

    int found = 0;

    struct Edge* first = g->adjList[src];
    while (first) {
        int mid = first->destination;

        struct Edge* second = g->adjList[mid];
        while (second) {
            if (second->destination == dest) {
                int totalCost = first->cost + second->cost;
                int totalTime = first->time + second->time;

                printf("%s -> %s -> %s | Cost: %d | Time: %d\n",
                       g->airportNames[src],
                       g->airportNames[mid],
                       g->airportNames[dest],
                       totalCost,
                       totalTime);

                found = 1;
            }
            second = second->next;
        }

        first = first->next;
    }

    if (!found)
        printf("No valid layover flights found.\n");
}
