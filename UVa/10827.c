#include <stdio.h>

#define INF 1 << 30

static int sum[300][300];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, n, i, j, k;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d ", &n);
		/* Calcular la suma acumulada en cada columna, duplicando la matriz a su derecha */
		for (j = 0; j < n; ++j)
			scanf("%d ", &sum[0][j]);
		for (i = 1; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d ", &sum[i][j]);
				sum[i][j] += sum[i-1][j];
			}
		}
		/* Extender la matriz por abajo para simular el toro */
		for (i = n; i < n * 2; ++i)
			for (j = 0; j < n; ++j)
				sum[i][j] = sum[i-n][j] + sum[n-1][j];

		/* Buscar la mejor submatriz iterando por filas */
		int result = sum[0][0], maxsum, minsum, colsum, colmax, colmin, currentcol;
		for (i = 0; i < n; ++i) {
			for (j = i; j < i + n; ++j) {

				/* Buscar el máximo, mínimo y total */
				maxsum = -INF;
				minsum = INF;
				colsum = colmax = colmin = 0;
				for (k = 0; k < n; ++k) {
					currentcol = sum[j][k];
					if (i > 0) currentcol -= sum[i-1][k];
					colsum += currentcol;

					if (colmax >= 0)
						colmax += currentcol;
					else
						colmax = currentcol;

					if (colmin <= 0)
						colmin += currentcol;
					else
						colmin = currentcol;

					if (colmax > maxsum) maxsum = colmax;
					if (colmin < minsum) minsum = colmin;
				}

				/* Simulación del wrapping: o el máximo es lo mejor, o el total menos el mínimo */
				if (maxsum > result)
					result = maxsum;
				if (colsum - minsum > result && colsum - minsum != 0)
					result = colsum - minsum;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}
