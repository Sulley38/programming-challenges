#include <stdio.h>

static int sum[100][100];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i, j, k;
	scanf("%d ", &n);
	/* Calcular la suma acumulada en cada columna */
	for (j = 0; j < n; ++j)
		scanf("%d ", &sum[0][j]);
	for (i = 1; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf("%d ", &sum[i][j]);
			sum[i][j] += sum[i-1][j];
		}
	}

	/* Buscar la mejor submatriz iterando por filas */
	int maxsum = sum[0][0], colsum;
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			/* Sabiendo el valor de cada columna, buscar la mejor secuencia */
			colsum = 0;
			for (k = 0; k < n; ++k) {
				colsum += sum[j][k];
				if (i > 0) colsum -= sum[i-1][k];
				/* Guardar el mejor valor */
				if (colsum > maxsum) maxsum = colsum;
				/* Reiniciar la cuenta si se baja del cero */
				if (colsum < 0) colsum = 0;
			}
		}
	}

	printf("%d\n", maxsum);

	return 0;
}
