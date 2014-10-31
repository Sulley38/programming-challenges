#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))
#define INF 10000000

int CostByDepth[250][250], CostIndep[250][250];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, F[250];
	int i, j, k, aux;
	while (scanf("%d ", &N) > 0) {
		for (i = 0; i < N; ++i) {
			scanf("%d ", &F[i]);
			CostByDepth[i][i] = F[i];
			CostIndep[i][i] = 0;
		}

		/* CostByDepth[i][i + k] * depth + CostIndep[i][i + k] = minimum cost of the search tree that is formed with nodes from (i) to (i + k) */
		for (k = 1; k < N; ++k) {
			for (i = 0; i < N - k; ++i) {
				/* Left-most element is the root */
				CostByDepth[i][i + k] = F[i] + CostByDepth[i + 1][i + k];
				CostIndep[i][i + k] = CostByDepth[i + 1][i + k] + CostIndep[i + 1][i + k];
				/* A middle element is the root */
				for (j = i + 1; j < i + k; ++j) {
					aux = CostByDepth[i][j - 1] + CostIndep[i][j - 1] + CostByDepth[j + 1][i + k] + CostIndep[j + 1][i + k];
					if (aux < CostIndep[i][i + k]) {
						CostByDepth[i][i + k] = CostByDepth[i][j - 1] + F[j] + CostByDepth[j + 1][i + k];
						CostIndep[i][i + k] = aux;
					}
				}
				/* Right-most element is the root */
				aux = CostByDepth[i][i + k - 1] + CostIndep[i][i + k - 1];
				if (aux < CostIndep[i][i + k]) {
					CostByDepth[i][i + k] = CostByDepth[i][i + k - 1] + F[i + k];
					CostIndep[i][i + k] = aux;
				}
			}
		}

		printf("%d\n", CostIndep[0][N - 1]);
	}


	return 0;
}
