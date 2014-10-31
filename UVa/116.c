#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int C[10][100]; /* C[i][j] = cost of the minimum path from cell (i,j) to an ending cell */
int Path[10][100]; /* Next row in the best path from the cell (i,j) */

void choose(int i, int j) {
	int minVal = i, up = (i - 1 + N) % N, down = (i + 1) % N;
	Path[i][j] = i;
	if (C[up][j + 1] < C[minVal][j + 1] || (C[up][j + 1] == C[minVal][j + 1] && up < minVal)) {
		minVal = up;
		Path[i][j] = up;
	}
	if (C[down][j + 1] < C[minVal][j + 1] || (C[down][j + 1] == C[minVal][j + 1] && down < minVal)) {
		minVal = down;
		Path[i][j] = down;
	}
	C[i][j] += C[minVal][j + 1];
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i, j;
	while (scanf("%d %d ", &N, &M) > 0) {
		for (i = 0; i < N; ++i)
			for (j = 0; j < M; ++j)
				scanf("%d ", &C[i][j]);

		/* Fill DP table */
		for (j = M - 2; j >= 0; --j)
			for (i = 0; i < N; ++i)
				choose(i, j);

		/* Get the minimum cost from the values in the first column */
		int min = 0;
		for (i = 1; i < N; ++i)
			if (C[i][0] < C[min][0])
				min = i;

		i = min;
		for (j = 0; j < M - 1; ++j) {
			printf("%d ", i + 1);
			i = Path[i][j];
		}
		printf("%d\n%d\n", i + 1, C[min][0]);
	}

	return 0;
}
