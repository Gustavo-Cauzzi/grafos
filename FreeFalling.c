#include<stdio.h>
#include<math.h>

#define MAX_P 500

float distance (int x1, int x2, int y1, int y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

float prim(float adj[MAX_P][MAX_P], int numPeople) {
    int i, nodesConnected[MAX_P];
    float distances[MAX_P];
    
    for(i = 0; i < numPeople; i++) {
        nodesConnected[i] = 0;
        distances[i] = INFINITY;
    }

    distances[0] = 0;

    for (i = 0; i < numPeople; i++) {
        float menor = INFINITY;
        
        int j, closestGraph;
        for (j = 0; j < numPeople; j++) {
            if (nodesConnected[j] == 0 && distances[j] < menor) {
                menor = distances[j];
                closestGraph = j;
            }
        }

        nodesConnected[closestGraph] = 1;

        for (j = 0; j < numPeople; j++) {
            if (nodesConnected[j] == 0 && adj[closestGraph][j] < distances[j]) {
                distances[j] = adj[closestGraph][j];
            }
        }
    }

    float sum = 0;
    for (i = 0; i < numPeople; i++) {
        sum += distances[i];
        nodesConnected[i] = 0;
        distances[i] = 0;
    }
    return sum;
}

int main(){
    int testCases;
    scanf("%d", &testCases);

    int t;
    for (t = 0; t < testCases; t++) {
        int numPeople;
        scanf("%d", &numPeople);

        float adj[MAX_P][MAX_P];
        int coordx[MAX_P], coordy[MAX_P];

        int i, j;
        for (i = 0; i < numPeople; i++) {
            scanf("%d %d", &coordx[i], &coordy[i]);
        }
        
        for (i = 0; i < numPeople; i++) {
            for (j = 0; j < numPeople; j++) {
                adj[i][j] = distance(coordx[i], coordx[j], coordy[i], coordy[j]);
            }
        }

        float result = prim(adj, numPeople);

        printf("%.2f\n", result / 100.0);
    }
    
    return 0;
}
