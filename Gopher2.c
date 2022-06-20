#include<stdio.h>
#include<math.h>

#define true 1
#define false 0

#define INF 10000000
#define N 100

float distance (float x1, float x2, float y1, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
 
int floydFulkerson () {
    //  while (1) {
    //     int ftot = 0, i;
    //     for (i = 0; i < N; i++) {
    //         ftot += F[0][i];
    //         visit[i] = 0;
    //     }

    //     printf("\nFluxo atual eh %d\n", ftot);
    //     for (i = 0; i < 13; i++) {
    //         int j;
    //         for (j = 0; j < 13; j++)
    //             printf("%2d ", F[i][j]);
    //         printf("\n");
    //     }

    //     if (!bfs(0, 12, 13)) {
    //         printf("Nao ha caminho aumentante\n");
    //         break;
    //     }
    // }
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
    }
    for (i = 0; i < num_holes; i++) {
        scanf("%f %f", &h_coordx[i], &h_coordy[i]);
    }

    for (i = 0; i < num_gophers; i++) {
        for (j = 0; j < num_holes; j++) {
            float d = distance(g_coordx[i], h_coordx[j], g_coordy[i], h_coordy[j]);
            adj[i][j + num_holes] = d;
            adj[j + num_holes][i] = d;
        }
    }

    for (i = 0; i < num_gophers + num_holes; i++) {
        for (j = 0; j < num_holes + num_holes; j++) {
            printf("%0.2f ", adj[i][j]);
        }
        printf("\n");
    }

    // hc_karp(adj, num_gophers, num_holes);

	return 0;
}