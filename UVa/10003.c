#include <stdio.h>
#include <string.h>

#define MAXN 50
#define min(a,b) ((a > b) ? b : a)

int cortes[MAXN];
int costemin[MAXN][MAXN];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int l, n, i, j, k;
	scanf("%d ", &l);
	while (l > 0) {
		/* Leer datos de entrada */
		scanf("%d ", &n);
		cortes[0] = 0;
		for (i = 1; i <= n; ++i)
			scanf("%d ", &cortes[i]);
		cortes[++n] = l;
		/* Inicializar matriz de costes a cero */
		memset(costemin, 0, sizeof(costemin));
		/* Calcular de forma ascendente los costes */
		/* costemin[i][j] = coste mínimo en realizar los cortes entre Ci..Cj */
		for (k = 2; k <= n; ++k) {
			for (i = 0; i + k <= n; ++i) {
				costemin[i][i+k] = costemin[i][i+1] + costemin[i+1][i+k];
				for (j = 2; j < k; ++j)
					costemin[i][i+k] = min(costemin[i][i+k], costemin[i][i+j] + costemin[i+j][i+k]);
				costemin[i][i+k] += cortes[i+k] - cortes[i];
			}
		}
		/* Imprimir resultado */
		printf("The minimum cutting is %d.\n", costemin[0][n]);
		scanf("%d ", &l);
	}

	return 0;
}
