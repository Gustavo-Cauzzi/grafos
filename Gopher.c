#include<stdio.h>
#include<math.h>

#define INF 10000000
#define N 100

float dist[N];
int pair_u[N], pair_v[N];

#define TESTE 10
float adj[TESTE][TESTE] = {
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
};

float distance (float x1, float x2, float y1, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int hc_karp(int num_u, int num_v) {
    int i, j;

    for (i = 0; i < num_u; i++) {
        pair_u[i] = -1;
    }
    for (i = 0; i < num_v; i++) {
        pair_v[i] = -1;
    }

    int matching = 0;

    while(bfs()) {
        int u;
        printf("9 ");
        for (u = 0; u < num_u; u++) {
            if (pair_u[u] == -1) {
                if (dfs(u, num_v)) {
                    matching++;
                }
            }
        }
    }

    return matching;
}

int dfs(int u, int num_v) {
    if (u == -1) {
        int v;
        for (v = 0; v < num_v; v++){
            printf("%c", v == -1 ? '@' : '-');
            if (dist[pair_v[v]] == dist[u] + 1) {
                if (dfs(pair_v[v], num_v)) {
                    pair_v[v] = u;
                    pair_u[u] = v;
                    return 1;
                }
            }
        }

        dist[u] = INF;
        return 0;
    }
    return 1;
}

int bfs() {
    // printf("1");
    int i;
    int fila[N], td = 0, pa = 1; // tira daqui | põe aqui
    
    for (i = 0; i < N; i++) {
        if(pair_u[i] == -1) {
            dist[i] = 0;
            fila[td] = i;
        } else {
            dist[i] = INF;
        }
    }

    float total_distance = INF;
    while (td < pa) {
        int u = fila[td++];
        if(dist[u] < total_distance) {
            int v;
            for (v = 0; v < N; v++) {
                if (pair_v[v] == -1) {
                    total_distance = dist[u] + 1;
                } else if (dist[pair_v[v]] == INF) { // Vértice do conjunto v é livre
                    dist[pair_v[v]] = dist[u] + 1;
                    fila[pa++] = pair_v[v];
                }
            }
        }
    }

    return total_distance == INF ? 0 : 1;
}

int main(){
    // n, m, s, v
	// int num_gophers, num_holes, seconds, velocity;
    // // g = gopher, h = holes
    // float g_coordx[N], g_coordy[N];
    // float h_coordx[N], h_coordy[N];
    // float adj[N][N];

    // scanf("%d %d %d %d",&num_gophers, &num_holes, &seconds, &velocity);

    // int i, j;
    // for (i = 0; i < num_gophers; i++) {
    //     scanf("%f %f", &g_coordx[i], &g_coordy[i]);
    // }
    // for (i = 0; i < num_holes; i++) {
    //     scanf("%f %f", &h_coordx[i], &h_coordy[i]);
    // }

    // for (i = 0; i < num_gophers; i++) {
    //     for (j = 0; j < num_holes; j++) {
    //         adj[i][j] = distance(g_coordx[i], h_coordx[j], g_coordy[i], h_coordy[j]);
    //     }
    // }

    // printf("retorno: %d", hc_karp(num_gophers, num_holes));
    printf("retorno: %d", hc_karp(TESTE, TESTE));

	return 0;
}