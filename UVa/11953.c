#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))
#define INF 10000000

int N;
char grid[100][102];

void fill(int i, int j) {
	int k;
	grid[i][j] = '@';
	for (k = 1; i - k >= 0 && grid[i - k][j] != '.'; grid[i - k][j] = '@', k++);
	for (k = 1; i + k < N && grid[i + k][j] != '.'; grid[i + k][j] = '@', k++);
	for (k = 1; j - k >= 0 && grid[i][j - k] != '.'; grid[i][j - k] = '@', k++);
	for (k = 1; j + k < N && grid[i][j + k] != '.'; grid[i][j + k] = '@', k++);
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, caso, i, j;
	scanf("%d ", &T);
	for (caso = 1; caso <= T; ++caso) {
		scanf("%d ", &N);
		for (i = 0; i < N; ++i)
			fgets(grid[i], N + 2, stdin);

		int count = 0;
		for (i = 0; i < N; ++i)
			for (j = 0; j < N; ++j)
				if (grid[i][j] == 'x') {
					count++;
					fill(i, j);
				}

		printf("Case %d: %d\n", caso, count);
	}

	return 0;
}
