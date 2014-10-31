#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mod(int a, int b) {
	if (a < 0)
		return (a + (a / b + 1) * b) % b;
	else
		return a % b;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, Q, D, M, A[201];
	int i, j, k, aux, q, set = 1;

	long long int Comb[201][11][20];
	memset(Comb, 0, sizeof Comb);
	for (i = 0; i < 201; ++i)
		Comb[i][0][0] = 1;

	scanf("%d %d ", &N, &Q);
	while (N > 0 || Q > 0) {
		/* Leer el array */
		for (i = 1; i <= N; ++i)
			scanf("%d ", &A[i]);

		printf("SET %d:\n", set++);
		for (q = 1; q <= Q; ++q) {
			scanf("%d %d ", &D, &M);
			/* Buscar combinaciones */

			/* Comb[i][j][k] = Número de combinaciones cogiendo j números de entre 1..i que sumen k (mod D) */
			for (i = 1; i <= N; ++i)
				for (j = 1; j <= i && j <= M; ++j)
					for (k = 0; k < D; ++k) {
						Comb[i][j][k] = Comb[i-1][j][k];
						aux = mod(k - mod(A[i], D), D);
						Comb[i][j][k] += Comb[i-1][j-1][aux];
					}

			printf("QUERY %d: %Ld\n", q, Comb[N][M][0]);
		}
		scanf("%d %d ", &N, &Q);
	}

	return 0;
}
