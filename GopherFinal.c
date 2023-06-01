#include<stdio.h>
#include<math.h>

#define N 200

double g_coordx[N], g_coordy[N];
double h_coordx[N], h_coordy[N];
int adj[N][N];

double distance (double x1, double x2, double y1, double  y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int find_augmenting_path_dfs (int gopher, int visited[N], int gopher_hole_relation[N], int num_gophers, int num_holes) {
    int hole, j;
    for (hole = 0; hole < num_holes; hole++) {
        if (adj[gopher][hole + num_gophers] == 1 && visited[hole] == 0) {
            visited[hole] = 1;
            if (
                gopher_hole_relation[hole] == -1 
            || find_augmenting_path_dfs(gopher_hole_relation[hole], visited, gopher_hole_relation, num_gophers, num_holes)
            ) {
                gopher_hole_relation[hole] = gopher;
                return 1;
            }
        }
    }
    return 0;
}

int floyd_fulkerson(int num_gophers, int num_holes) {
    int visited[N], gopher_hole_relation[N], gopher, hole;
    for (hole = 0; hole < num_holes; hole++) {
        gopher_hole_relation[hole] = -1;
    }

    int matching = 0;
    for (gopher = 0; gopher < num_gophers; gopher++) {
        for(hole = 0; hole < num_holes; hole++) {
            visited[hole] = 0;
        }

        matching += find_augmenting_path_dfs(
            gopher, 
            visited, 
            gopher_hole_relation, 
            num_gophers, 
            num_holes
        );
    }

    return matching;
}

int main(){
	int num_gophers, num_holes, seconds, velocity;

	while (scanf("%d %d %d %d", &num_gophers, &num_holes, &seconds, &velocity) != EOF) {
        int i, j;
        int num_vertecies = num_gophers + num_holes + 2;
        for (i = 0; i < num_vertecies; i++) {
            for (j = 0; j < num_vertecies; j++) {
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
                adj[i][num_gophers + j] = (d <= velocity * seconds);
			}
		}

        printf("%d\n", num_gophers - floyd_fulkerson(num_gophers, num_holes));
    }   

    return 0;
}