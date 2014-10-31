#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	long long int dp[51][51][51];
	int n, k, m, i;
	/* Casos básicos */
	for (n = 1; n <= 50; ++n) {
		/* Longitud n, n barras de tamaño máximo al menos 1 */
		for (m = 1; m <= 50; ++m)
			dp[n][n][m] = 1;
		/* Longitud n, 1 barras de tamaño máximo al menos n */
		for (m = n; m <= 50; ++m)
			dp[n][1][m] = 1;
	}
	/* Resto de casos */
	for (n = 2; n <= 50; ++n)
		for (k = 2; k < n; ++k) {
			/* A los que haya de una barra menos, añadirle barras hasta un máximo de m */
			for (m = 2; m <= n - k + 1; ++m) {
				dp[n][k][m] = 0;
				for (i = 1; i <= m; ++i)
					dp[n][k][m] += dp[n - i][k - 1][m];
			}
			/* Copiar el resultado del último m hallado hasta 50 */
			for (m = n - k + 2; m <= 50; ++m)
				dp[n][k][m] = dp[n][k][n - k + 1];
		}

	while (scanf("%d %d %d ", &n, &k, &m) > 0)
		printf("%lld\n", dp[n][k][m]);

	return 0;
}
