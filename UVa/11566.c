#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MaxFav[i][j][k] = Máximo agrado que se puede lograr considerando los platos 1..i
 * pudiendo elegir hasta j platos y gastando como mucho k$.
*/
int MaxFav[101][23][1001];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, x, T, K;
	int price[101], favor[101];
	scanf("%d %d %d %d ", &N, &x, &T, &K);

	int i, j, k, maxDimSum;
	for (j = 0; j < 23; ++j)
		for (k = 0; k < 101; ++k)
			MaxFav[0][j][k] = 0;
	for (i = 0; i < 101; ++i)
		for (k = 0; k < 101; ++k)
			MaxFav[i][0][k] = 0;

	while (N > 0 || x > 0 || T > 0 || K > 0) {
		/* Leer la entrada */
		N++;
		for (i = 1; i <= K; ++i) {
			scanf("%d ", &price[i]);
			favor[i] = 0;
			for (j = 0; j < N; ++j) {
				scanf("%d ", &k);
				favor[i] += k;
			}
		}
		/* Dinero máximo que se puede gastar en comida (descontar té y propina) */
		maxDimSum = floor((x * N) / 1.1 + 1e-6) - T * N;
		/* Rellenar tabla por DP */
		for (i = 1; i <= K; ++i) {
			for (j = 1; j <= 2*N; ++j) {
				for (k = 0; k <= maxDimSum; ++k) {
					/* No coger ningún plato del tipo i */
					MaxFav[i][j][k] = MaxFav[i-1][j][k];
					/* Coger un plato del tipo i */
					if (k - price[i] >= 0 && MaxFav[i-1][j-1][k - price[i]] + favor[i] > MaxFav[i][j][k])
						MaxFav[i][j][k] = MaxFav[i-1][j-1][k - price[i]] + favor[i];
					/* Coger dos platos del tipo i */
					if (k - 2 * price[i] >= 0 && j - 2 >= 0 && MaxFav[i-1][j-2][k - 2 * price[i]] + 2 * favor[i] > MaxFav[i][j][k])
						MaxFav[i][j][k] = MaxFav[i-1][j-2][k - 2 * price[i]] + 2 * favor[i];
				}
			}
		}

		printf("%.2lf\n", MaxFav[K][2*N][maxDimSum] / ((double)N));
		scanf("%d %d %d %d ", &N, &x, &T, &K);
	}

	return 0;
}
