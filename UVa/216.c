#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 8

double mod(int X1, int X2, int Y1, int Y2) {
	return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

double dist[MAXN][MAXN];
int n;

/* Calculate minimum cable needed to cover the computers not checked in the bitmask 'unidos',
 * extending from either 'primero' or 'ultimo'. Stores the sequence in 'seq' */
double mincable(int primero, int ultimo, int unidos, int numunidos, int * seq) {
	if (numunidos == n) {
		return 0.0;
	} else {
		/* Try from both ends with every computer not covered yet and solve recursively, return the minimum */
		double ans, minans = 1000000.0;
		int i, order[2 * MAXN], bestorder[2 * MAXN];
		for (i = 0; i < n; ++i) {
			if (!(unidos & (1 << i))) {
				memcpy(order, seq, 2 * MAXN * sizeof(int));
				order[ultimo + 1] = i;
				ans = mincable(primero, ultimo + 1, unidos | (1 << i), numunidos + 1, order);
				if (ans + dist[order[ultimo]][i] < minans) {
					minans = ans + dist[order[ultimo]][i];
					memcpy(bestorder, order, 2 * MAXN * sizeof(int));
				} else {
					order[ultimo + 1] = -1;
				}
				if (primero != ultimo) {
					memcpy(order, seq, 2 * MAXN * sizeof(int));
					order[primero - 1] = i;
					ans = mincable(primero - 1, ultimo, unidos | (1 << i), numunidos + 1, order);
					if (ans + dist[order[primero]][i] < minans) {
						minans = ans + dist[order[primero]][i];
						memcpy(bestorder, order, 2 * MAXN * sizeof(int));
					} else {
						order[primero - 1] = i;
					}
				}
			}
		}
		memcpy(seq, bestorder, 2 * MAXN * sizeof(int));
		return minans;
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t = 1, X[MAXN], Y[MAXN], order[2 * MAXN];
	int i, j;
	double ans;

	while (scanf("%d ", &n) > 0 && n > 0) {
		/* Read positions */
		for (i = 0; i < n; ++i)
			scanf("%d %d ", &X[i], &Y[i]);
		/* Compute distances */
		for (i = 0; i < n; ++i)
			for (j = i + 1; j < n; ++j)
				dist[i][j] = dist[j][i] = mod(X[i], X[j], Y[i], Y[j]) + 16;
		/* Calculate minimum distance, starting point fixed at node 0 */
		memset(order, -1, sizeof order);
		order[7] = 0;
		ans = mincable(7, 7, 1, 1, order);
		/* Print the result */
		puts("**********************************************************");
		printf("Network #%d\n", t++);
		for (i = 0; i < 2 * MAXN - 1; ++i)
			if (order[i] >= 0 && order[i + 1] >= 0)
				printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", X[order[i]], Y[order[i]], X[order[i+1]], Y[order[i+1]], dist[order[i]][order[i+1]]);
		printf("Number of feet of cable required is %.2lf.\n", ans);
	}

	return 0;
}
