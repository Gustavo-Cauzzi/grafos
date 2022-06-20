#include<stdio.h>
#include<math.h>

#define true 1
#define false 0

#define INF 1000000000
#define N 102

#define max(a, b)(a) > (b) ? (a) : (b)
#define min(a, b)(a) < (b) ? (a) : (b)

#define cont(i, j) flux[j][i]
#define dir(i, j)(adj[i][j] - flux[i][j])

double g_coordx[N], g_coordy[N];
double h_coordx[N], h_coordy[N];
int adj[N][N], flux[N][N];
int fila_bfs[N], pai[N], menor[N];

float distance (float x1, float x2, float y1, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int ff_bfs (int s, int t, int num_vertecies, int visited[N]) {
    int TD = 0, PA = 1, i;
    visited[s] = 1;
    fila_bfs[0] = s;
    menor[s] = INF;

    while (visited[t] == 0 && TD != PA) {
        int v = fila_bfs[TD++];
        for (i = 0; i < num_vertecies; i++) {
            if (visited[i] == 0 && (dir(v, i) || cont(v, i))) {
                visited[i] = 1;
                menor[i] = min(menor[v], max(dir(v, i), cont(v, i)));
                pai[i] = v;
                fila_bfs[PA++] = i;
            }
        }
    }

    if (visited[t] == 0) return false;

    int smallest_value = menor[t];
    int aux = t;
    while (aux != s) {
        int v = pai[aux];
        if (dir(v, aux) >= smallest_value) {
            flux[v][aux] += smallest_value;
        } else {
            flux[aux][v] -= smallest_value;
        }
        aux = v;
    }

    return true;
}

int floyd_fulkerson(int source, int target, int num_vertecies) {
    int visited[N], i, j;
    while (true) {
        int total_flux = 0;
        for (i = 0; i < num_vertecies; i++) {
            total_flux += flux[source][i];
            visited[i] = 0;
        }

        if(!ff_bfs(source, target, num_vertecies, visited)) {
            printf("total_flux: %d \n", total_flux);
            return total_flux;
        };
    }
}

int main(){
	int num_gophers, num_holes, seconds, velocity;

    while(scanf("%d %d %d %d",&num_gophers, &num_holes, &seconds, &velocity) != EOF){
        int i, j;
        int num_vertecies = num_gophers + num_holes + 2;
        for (i = 0; i < num_vertecies; i++) {
            for (j = 0; j < num_vertecies; j++) {
                adj[i][j] = 0;
            }
        }
        for (i = 0; i < num_gophers; i++) {
            scanf("%lf %lf", &g_coordx[i], &g_coordy[i]);
            adj[num_gophers + num_holes][i] = 1;
        }

        for (i = 0; i < num_holes; i++) {
            scanf("%lf %lf", &h_coordx[i], &h_coordy[i]);
            adj[num_gophers + i][num_gophers + num_holes + 1] = 1;
        }

		for (i = 0; i < num_gophers; i++) {
			for (j = 0; j < num_holes; j++) {
                double d = distance(g_coordx[i], h_coordx[j], g_coordy[i], h_coordy[j]);
                adj[i][num_gophers + j] = (d <= (double) velocity * (double) seconds) ? 1 : 0;
			}
		}

        printf("    ");
        for (i = 0; i < num_vertecies; i++) {
            if (i < 10) {
                printf("%d ", i);
            } else {
                printf("%d", i);
            }
        }
        printf("\n");
		for (i = 0; i < num_vertecies; i++) {
            if (i < 10) {
                printf("%d - ", i);
            } else {
                printf("%d- ", i);
            }

			for (j = 0; j < num_vertecies; j++) {
                printf("%d ", adj[i][j]);
			}
            printf("\n");
		}

        printf("%d", num_gophers - floyd_fulkerson(num_vertecies - 2, num_vertecies - 1, num_vertecies));
    }

	return 0;
}