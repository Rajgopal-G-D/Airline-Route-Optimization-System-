#include "graph.h"

int main() {
    int n, e;
    printf("Enter number of airports and routes: ");
    scanf("%d %d", &n, &e);

    struct Graph* g = createGraph(n);
    printf("Enter airport names:\n");
    for (int i = 0; i < n; i++) scanf("%s", g->airportNames[i]);

    printf("Enter routes (src dest cost time):\n");
    for (int i = 0; i < e; i++) {
        char s1[50], s2[50];
        int cost, time;
        scanf("%s %s %d %d", s1, s2, &cost, &time);
        int src = getAirportIndex(g, s1);
        int dest = getAirportIndex(g, s2);
        addEdge(g, src, dest, cost, time);
    }

    int choice;
    while (1) {
        printf("\n----- Airline Route Optimization -----\n");
        printf("1. Represent Airports\n");
        printf("2. Find Cheapest Path\n");
        printf("3. Find Fastest Path\n");
        printf("4. Optimize Multi-Hop Flights\n");
        printf("5. Show All Stored Flights\n");
        printf("6. Show Layover Options\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 7) break;

        char s1[50], s2[50];
        switch (choice) {
            case 1:
                representAirports(g);
                break;

            case 2:
                printf("Enter source and destination: ");
                scanf("%s %s", s1, s2);
                findCheapestPath(g, getAirportIndex(g, s1), getAirportIndex(g, s2));
                break;

            case 3:
                printf("Enter source and destination: ");
                scanf("%s %s", s1, s2);
                findFastestPath(g, getAirportIndex(g, s1), getAirportIndex(g, s2));
                break;

            case 4:
                printf("Enter source and destination: ");
                scanf("%s %s", s1, s2);
                optimizeMultiHopFlights(g, getAirportIndex(g, s1), getAirportIndex(g, s2));
                break;

            case 5:
                storeFlights(g);
                break;

            case 6:
                printf("Enter source and destination: ");
                scanf("%s %s", s1, s2);
                handleLayovers(g, getAirportIndex(g, s1), getAirportIndex(g, s2));
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
