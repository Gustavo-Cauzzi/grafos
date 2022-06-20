#include<stdio.h>
#include<math.h>

#define MAX_C 500

float distance (float x1,float x2,float y1,float y2) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void printArray(int array[]) {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void printArray2(float array2[MAX_C][MAX_C]) {
	int i, j;
	printf("--\n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%f ", array2[i][j]);
		}
		printf("\n");
	}
	printf("--\n");
}


int main(){
	int numComputers, i, j;
	float adj[MAX_C][MAX_C];
	int coordX[MAX_C], coordY[MAX_C];
	
	while(scanf("%d", &numComputers) != EOF) {
		for(i = 0; i < numComputers; i++) {
			scanf("%d %d", &coordX[i], &coordY[i]);
		}
		
		for(i = 0; i < numComputers; i++) {
			for(j = 0; j < i; j++) {
				adj[i][j] = distance(coordX[i], coordX[j], coordY[i], coordY[j]);
			}
		}
		
		int connectedNodes[MAX_C], notConnectedNodes[MAX_C];
		int numConnectedNodes = 1;
		float totalLength = 0;
		
		// Adiciona o nodo 0 como parte do sistema
		connectedNodes[0] = 0;
		
		// Adiciona todos os outros como nodos desconexos do sistema
		for(i = 1; i < numComputers; i++) notConnectedNodes[i - 1] = i;
		
		while(numConnectedNodes < numComputers) {
			float smallestDistance = 9999999999;
			int closestNode = NULL;
			
			for (i = 0; i < numComputers; i++) {
				int conNode = connectedNodes[i];
				for (j = 0; j < numComputers - numConnectedNodes; j++) {
					int possibleConNode = notConnectedNodes[j];
					
					// Abaixo, conNode e possibleConNode poder�o ser trocados. Para isso
					// guardamos qual deles realmente � o node que poder� ser adicionado ou n�o
					int bkpPosConNode = possibleConNode;
					if (conNode < possibleConNode) {
						int aux = conNode;
						conNode = possibleConNode;
						possibleConNode = aux;
					}
					
					if (adj[conNode][possibleConNode] < smallestDistance) {
						smallestDistance = adj[conNode][possibleConNode];
						closestNode = bkpPosConNode;
					}
				}
			}
			
			// Remover elemento do vetor de notConnectedNodes
			int newArray[MAX_C], a = 0;
			for(i = 0; i < numComputers - numConnectedNodes; i++) {
				if (notConnectedNodes[i] != closestNode) {
					notConnectedNodes[a] = notConnectedNodes[i];
					a++;
				}
			}
			
			// Adiciona nodo para lista de nodos conectados e soma a dist�ncia
			connectedNodes[numConnectedNodes] = closestNode;
			numConnectedNodes++;
			totalLength += smallestDistance;
		}
		
		printf("%.2f\n", totalLength);
		
		// Zera tudo
		for (i = 0; i < numComputers; i++) {
			connectedNodes[i] = 0;
			notConnectedNodes[i] = 0;
			for (j = 0; j < i; j++) {
				adj[i][j] = 0;
			}
		}
	}
	
	return 0;
}
