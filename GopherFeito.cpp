#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;

vi match, vis; // global variables
vector<vi> AdjList;

int Aug(int l) { // return 1 if there exists an augmenting path
	if (vis[l])
		return 0; // return 0 otherwise
	vis[l] = 1;
	for (int j = 0; j < (int) AdjList[l].size(); j++) {
		int r = AdjList[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1; // found 1 matching
		}
	}
	return 0; // no matching
}

double gx[105], gy[105], hx[105], hy[105];

double dist(int g, int h) {
	return sqrt(
			(gx[g] - hx[h]) * (gx[g] - hx[h])
					+ (gy[g] - hy[h]) * (gy[g] - hy[h]));
}

int main() {
	int V, VLeft;
	int n, m, s, v;

	while (scanf("%d %d %d %d", &n, &m, &s, &v) != EOF) {
		V = n + m;
		VLeft = n;
		AdjList.assign(V, vi());
        double adj[100][100];

		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &gx[i], &gy[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%lf %lf", &hx[i], &hy[i]);
		}

		for (int g = 0; g < n; g++) {
			for (int h = 0; h < m; h++) {
                adj[g][n + h] = s > (dist(g, h) / (double) v);
			}
		}

		for (int g = 0; g < n + m; g++) {
			for (int h = 0; h < n + m; h++) {
				printf("%0.0f ", adj[g][h]);
			}
            printf("\n");
		}

		int MCBM = 0;
		match.assign(V, -1);

		for (int l = 0; l < VLeft; l++) {
			vis.assign(VLeft, 0);
			MCBM += Aug(l);
		}

		printf("%d\n", n - MCBM);
	}
	return 0;
}
