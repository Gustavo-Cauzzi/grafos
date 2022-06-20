#include<stdio.h>
#include<math.h>

#define N 10

double g_coordx[N], g_coordy[N];
double h_coordx[N], h_coordy[N];
double adj[N][N];

double distance (double x1, double x2, double y1, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int find_augmenting_path_dfs (int gopher, int visited[N], int gopher_hole_relation[N], int num_gophers, int num_holes) {
    int i, j;
    if (visited[gopher]) return 0;
    visited[gopher] = 1;
    printf("- %lf \n", adj[gopher][j]);
    for (i = 0; i < (num_gophers + num_holes); i++) {
        if (gopher_hole_relation[(int) adj[gopher][j]] == -1 
        || find_augmenting_path_dfs(gopher_hole_relation[j], visited, gopher_hole_relation, num_gophers, num_holes)) {
			gopher_hole_relation[j] = gopher;
			return 1;
        }
    }
    return 0;
}

int floyd_fulkerson(int num_gophers, int num_holes) {
    printf("0-=-=-\n");
    int visited[N], gopher_hole_relation[N], i, j;
    for (i = 0; i < N; i++) {
        gopher_hole_relation[i] = -1;
    }

    int coisa = 0;
    for (i = 0; i < num_gophers; i++) {
        for(j = 0; j < num_gophers; j++) {
            visited[j] = 0;
        }

        coisa += find_augmenting_path_dfs(
            i, 
            visited, 
            gopher_hole_relation, 
            num_gophers, 
            num_holes
        );
    }
    int coisa2;
    for (i = 0; i < num_gophers; i++) {
        coisa2 += gopher_hole_relation[i] != -1;
    }

    printf("coisa: %d\n", coisa);
    printf("coisa2: %d\n", coisa2);
    return coisa;
}

int main(){
	int num_gophers, num_holes, seconds, velocity;

	while (scanf("%d %d %d %d", &num_gophers, &num_holes, &seconds, &velocity) != EOF) {
        int i, j;
        for(i = 0; i < (num_gophers + num_holes); i++) {
            for(j = 0; j < (num_gophers + num_holes); j++) {
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
                adj[i][num_gophers + j] = (seconds > (d / (double) velocity)) ? (num_gophers + j) : 0;
			}
		}

		for (i = 0; i < (num_gophers + num_holes); i++) {
			for (j = 0; j < (num_gophers + num_holes); j++) {
				printf("%0.0f ", adj[i][j]);
			}
            printf("\n");
		}

        printf("%d\n", num_gophers - floyd_fulkerson(num_gophers, num_holes));
    }   

    return 0;
}