#include<stdio.h>
#include<math.h>

#define true 1
#define false 0

#define N 102

double distance (double x1, double x2, double y1, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int has_augmenting_path_dfs (double adj[N][N], int i, int visited[N], int gopher_hole[N]) {
    int j;
    if (visited[i]) return false;
    visited[i] = 1;
    for (j = 0; j < N; j++) {
        if (adj[i][j] != 0 && visited[j] == 0) {
            visited[j] = 1;
            if (gopher_hole[j] < 0 || has_augmenting_path_dfs(adj, gopher_hole[j], visited, gopher_hole)) {
                gopher_hole[j] = i;
                return true;
            }
        }
    }
    return false;
}

int floyd_fulkerson(double adj[N][N], int num_gophers, int num_holes) {
    int i, j;
    int gopher_hole[N]; 
    for (i = 0; i < N; i++) {
        gopher_hole[i] = -1;
    }

    int visited[N];
    int matching = 0;
    for (i = 0; i < num_gophers; i++) {
        for (j = 0; j < N; j++) {
            visited[j] = 0;
        }
        
        matching += has_augmenting_path_dfs(adj, i, visited, gopher_hole);
    }
    return matching;
}

int main(){
	int num_gophers, num_holes, seconds, velocity;
    double g_coordx[N], g_coordy[N];
    double h_coordx[N], h_coordy[N];
    double adj[N][N];

	while (scanf("%d %d %d %d",&num_gophers, &num_holes, &seconds, &velocity) != EOF) {
        int i, j;
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                adj[i][j] = 0;
            }
        }
        
        for (i = 0; i < num_gophers; i++) {
            scanf("%lf %lf", &g_coordx[i], &g_coordy[i]);
        }
        
        for (i = 0; i < num_holes; i++) {
            scanf("%lf %lf", &h_coordx[i], &h_coordy[i]);
        }

        for (i = 0; i < num_gophers; i++) {
            for (j = 0; j < num_holes; j++) {
                double d = distance(g_coordx[i], h_coordx[j], g_coordy[i], h_coordy[j]);
                adj[i][j + num_holes] = d / velocity > seconds ? 0 : 1;
            }
        }

        printf("%d\n", num_gophers - floyd_fulkerson(adj, num_gophers, num_holes));
    }

	return 0;
}