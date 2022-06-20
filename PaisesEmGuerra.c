#include<stdio.h>
#include<math.h>

#define MAX_N 501
#define MAX_H 1001

int dijkstra(int adj[MAX_N][MAX_N], int numVertecies, int initialNode, int endNode) {
    int d[MAX_N], Q[MAX_N], visited[MAX_N];
    int i;
    for(i = 0; i < numVertecies; i++) {
        d[i] = MAX_H;
        Q[MAX_N] = i;
        visited[i] = 0;
    }
    
    d[initialNode] = 0;
    
    int analysingNode = initialNode;
    while (analysingNode != endNode) {      
        // Atualiza as distancias
        for(i = 0; i < numVertecies; i++) {
            if (d[i] > d[analysingNode] + adj[analysingNode][i]) {
                d[i] = d[analysingNode] + adj[analysingNode][i];
            }
        }
        
        int smallestDistance = MAX_H;
        visited[analysingNode] = 1;
        
        for (i = 0; i < numVertecies; i++) {
            if (d[i] < smallestDistance && visited[i] == 0) {
                smallestDistance = d[i];
                analysingNode = i;
            }
        }
        
        if (smallestDistance == MAX_H) {
            return MAX_H;
        }
    }
    
    return d[analysingNode];
}

int main(){
    while(1){
        int numCities, numRelations, i, j;
        scanf("%d %d",&numCities, &numRelations);
        
        if (numCities == 0 && numRelations == 0) {
            return 0;
        }
        
        int adj[MAX_N][MAX_N];
        for(i = 0; i < numCities; i++) {
            for(j = 0; j < numCities; j++) {
                adj[i][j] = MAX_H;
            }
        }
        
        for(i = 0; i < numRelations; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            if (adj[y - 1][x - 1] != MAX_H) {
                adj[x - 1][y - 1] = 0;
                adj[y - 1][x - 1] = 0;
            } else {
                adj[x - 1][y - 1] = h;
            }
        }
        
        int numSearches;
        scanf("%d", &numSearches);
        for(i = 0; i < numSearches; i++) {
            int city1, city2;
            scanf("%d %d", &city1, &city2);
            int distance = dijkstra(adj, numCities, city1 - 1, city2 - 1);
            if (distance == MAX_H) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", distance);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
