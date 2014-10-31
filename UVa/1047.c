#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso = 0, n, maxn, m, C[20];
	int Common[10][2], Found[10][20], i, j, k, match;
	int S[20], BestS[20], clientes, maxclientes;
	scanf("%d %d ", &n, &maxn);
	while (n > 0 || maxn > 0) {
		/* Leer la entrada */
		for (i = 0; i < n; ++i)
			scanf("%d ", &C[i]);
		scanf("%d ", &m);
		memset(Common, 0, sizeof Common);
		memset(Found, 0, sizeof Found);
		for (i = 0; i < m; ++i) {
			scanf("%d ", &Common[i][0]);
			for (j = 1; j <= Common[i][0]; ++j) {
				scanf("%d ", &k);
				Found[i][k - 1] = 1;
			}
			scanf("%d ", &Common[i][1]);
		}
		/* Procesar todas las combinaciones de maxn torres */
		for (i = 0; i < maxn; ++i)
			S[i] = i;
		maxclientes = -1;
		while (S[0] <= n - maxn) {
			/* Contar el número de clientes cubiertos y quedarse con el máximo */
			clientes = 0;
			for (i = 0; i < maxn; i++)
				clientes += C[S[i]];
			for (i = 0; i < m; i++) {
				match = 0;
				for (k = 0; k < maxn; ++k)
					if (Found[i][S[k]]) {
						if (match)
							clientes -= Common[i][1];
						else
							match = 1;
					}
			}
			if (clientes > maxclientes) {
				memcpy(BestS, S, maxn * sizeof(int));
				maxclientes = clientes;
			}
			/* Avanzar a la siguiente combinación */
			i = 1;
			while (i <= maxn && S[maxn - i] == n - i)
				i++;
			if (i <= maxn) {
				S[maxn - i]++;
				while (i > 1) {
					S[maxn - i + 1] = S[maxn - i] + 1;
					i--;
				}
			} else {
				S[0] = n;
			}
		}

		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:", ++caso, maxclientes);
		for (i = 0; i < maxn; ++i)
			printf(" %d", BestS[i] + 1);
		printf("\n\n");
		scanf("%d %d ", &n, &maxn);
	}

	return 0;
}
