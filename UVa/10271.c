#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))

int TB[1009][5000];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	memset(TB[0], 0, sizeof TB[0]);
	int T, K, N, A[5000];
	int i, j;
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &K, &N);
		for (i = 0; i < N; ++i)
			scanf("%d ", &A[i]);
		K += 8;

		/* TB[i][j] = mínimo badness al formar i conjuntos con los palillos del j al N - 1 */
		for (i = 1; i <= K; ++i) {
			/* Con menos de 3 * i palillos no se pueden formar suficientes conjuntos */
			j = N - 3 * i;
			TB[i][j] = TB[i - 1][j + 2] + SQR(A[j] - A[j + 1]);
			for (--j; j >= 0; --j)
				TB[i][j] = MIN(TB[i - 1][j + 2] + SQR(A[j] - A[j + 1]), TB[i][j + 1]);
		}

		printf("%d\n", TB[K][0]);
	}

	return 0;
}
