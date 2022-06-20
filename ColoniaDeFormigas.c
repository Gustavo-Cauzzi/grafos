// 1135 (LCA)
// Esclarecimento: anthils = formigueiros
#include<stdio.h>

#define MAX_ANTHILS 100001

int parent[MAX_ANTHILS], d_parent[MAX_ANTHILS], nivel[MAX_ANTHILS];

long long int calcDistance (int i, int f) {
	long long int distance = 0;
	while (i != f) {
		if (nivel[i] > nivel[f]) {
			distance += d_parent[i];
			i = parent[i];
		} else if (nivel[i] < nivel[f]) {
			distance += d_parent[f];
			f = parent[f];
		} else {
            distance += d_parent[i] + d_parent[f];
            i = parent[i];
            f = parent[f];
		}
	}
	
	return distance;
}

int main(){
	int anthills, i;
	while(1) {
		scanf("%d", &anthills);
		
		if (anthills == 0) {
			return 0;
		}
		
		for (i = 0; i < anthills; i++) {
	        parent[i] = -1;
	        d_parent[i] = -1;
	        nivel[i] = -1;
		}
		
	    nivel[0] = 0;
	    parent[0] = 0;
		
		int anthill;
		for(anthill = 1; anthill < anthills; anthill++) {
			int parentAnthill, distance;
			scanf("%d %d", &parentAnthill, &distance);
			
			parent[anthill] = parentAnthill;
			d_parent[anthill] = distance;
			nivel[anthill] = nivel[parentAnthill] + 1;
		}
		
		int numQueries;
		scanf("%d", &numQueries);
		for(i = 1; i <= numQueries; i++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			printf("%lld", calcDistance(v1, v2));
			if (i != numQueries) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
