#include<stdio.h>
#include<math.h>

#define true 1
#define false 0

#define N 102

float distance (float x1, float x2, float y1, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int bfs (float adj[N][N], int i, int visited[N], int gopher_hole[N], int max_seconds) {
    printf("- bfs\n");
    int j;
    for (j = 0; j < N; j++) {
        printf("-- adj[i][j + 2] %f | s: %d | v: %d | i: %d | j + 2: %d\n", adj[i][j + 2], max_seconds, visited[j], i, j + 2);
        if (adj[i][j + 2] != 0 && adj[i][j + 2] <= max_seconds && visited[j] == 0) {
            visited[j] = 1;
            printf("---\n");
            if (gopher_hole[j] < 0 || bfs(adj, gopher_hole[j], visited, gopher_hole, max_seconds)) {
                printf("---- gopher_hole[%d] = %d\n", j, i);
                gopher_hole[j] = i;
                return true;
            }
        }
    }
    return false;
}

int floyd_fulkerson(float adj[N][N], int num_gophers, int num_holes, int max_seconds) {
    int i, j;
    int gopher_hole[N]; // Controla qual gopher está em qual buraco atualmente
    for (i = 0; i < N; i++) {
        gopher_hole[i] = -1;
    }

    int visited[N];
    for (i = 0; i < num_gophers; i++) {
        for (j = 0; j < N; j++) {
            visited[j] = 0;
        }
        
        int a = bfs(adj, i, visited, gopher_hole, max_seconds);
        printf("retorno bfs a %d\n", a);
        printf("gopher_hole: ");
        for (j = 0; j < 7; j++) {
            printf("%d ", gopher_hole[j]);
        }
        printf("\n");
    }
    printf("bduiasbduisabudisabuisa");
    int matching = 0;
    for (i = 0; i < N; i++) {
        printf("%d ", gopher_hole[i]);
        if(gopher_hole[i] != -1) matching++;
    }
    return matching;
}

int main(){
    // n, m, s, v
	int num_gophers, num_holes, seconds, velocity;
    // g = gopher, h = holes
    float g_coordx[N], g_coordy[N];
    float h_coordx[N], h_coordy[N];
    float adj[N][N];

    scanf("%d %d %d %d",&num_gophers, &num_holes, &seconds, &velocity);

    int i, j;
    for (i = 0; i < num_gophers; i++) {
        scanf("%f %f", &g_coordx[i], &g_coordy[i]);
        adj[num_gophers + num_holes][i] = 1; // s
    }
    for (i = 0; i < num_holes; i++) {
        scanf("%f %f", &h_coordx[i], &h_coordy[i]);
        adj[num_gophers + i][num_gophers + num_holes + 1] = 1; // t
    }

    for (i = 0; i < num_gophers; i++) {
        for (j = 0; j < num_holes; j++) {
            float d = distance(g_coordx[i], h_coordx[j], g_coordy[i], h_coordy[j]);
            adj[i][j + num_holes] = d / velocity;
        }
    }

    for (i = 0; i < num_gophers + num_holes + 2; i++) {
        for (j = 0; j < num_holes + num_holes + 2; j++) {
            printf("%0.2f ", adj[i][j]);
        }
        printf("\n");
    }
    printf("teste: %f %f\n", adj[2][0], adj[0][2]);

    printf("Resultado: %d", floyd_fulkerson(adj, num_gophers, num_holes, seconds));
    printf("%d", floyd_fulkerson(adj, num_gophers, num_holes, seconds));

	return 0;
}