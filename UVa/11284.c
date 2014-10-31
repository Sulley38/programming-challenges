#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int P, dist[51][51], store[13], saving[13];
int done[13][1 << 13];
int dp[13][1 << 13];

/* Maximum saving from 'last' store having visited what 'visited' bitmask says */
int tsp(int last, int visited) {
	if (done[last][visited]) return dp[last][visited];
	int i, maxans, ans;
	/* Go back home */
	maxans = - dist[store[last]][0];
	/* Visit another store */
	for (i = 1; i <= P; ++i) {
		if ((visited & (1 << i)) == 0) {
			ans = tsp(i, visited | (1 << i)) - dist[store[last]][store[i]] + saving[i];
			if (maxans < ans)
				maxans = ans;
		}
	}
	done[last][visited] = 1;
	return (dp[last][visited] = maxans);
}

int main(void) {
	int S, N, M, i, j, k, pe, pd, maxsave;
	scanf("%d ", &S);
	while (S--) {
		scanf("%d %d ", &N, &M);
		for (i = 0; i <= N; ++i)
			for (j = 0; j <= N; ++j)
				dist[i][j] = 10000000;
		/* Read edges */
		while (M--) {
			scanf("%d %d %d.%d ", &i, &j, &pe, &pd);
			if (dist[i][j] > 100 * pe + pd)
				dist[i][j] = dist[j][i] = 100 * pe + pd;
		}
		/* All-pairs shortest paths */
		for (i = 0; i <= N; ++i)
			dist[i][i] = 0;
		for (k = 0; k <= N; ++k)
			for (i = 0; i <= N; ++i)
				for (j = 0; j <= N; ++j)
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
		/* Read DVDs */
		store[0] = saving[0] = 0;
		scanf("%d ", &P);
		for (i = 1; i <= P; ++i) {
			scanf("%d %d.%d ", &store[i], &pe, &pd);
			saving[i] = 100 * pe + pd;
		}
		/* Make TSP */
		memset(done, 0, sizeof done);
		maxsave = tsp(0, 1);
		if (maxsave > 0)
			printf("Daniel can save $%.2lf\n", maxsave / 100.0);
		else
			puts("Don't leave the house");
	}
	return 0;
}
