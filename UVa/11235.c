#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000
#define max(a,b) (a > b ? a : b)

static int freq[MAXN];
static int begin[MAXN], end[MAXN];
static int M[MAXN][17];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, q, i, j, k, a, valor, repeticiones, ultimapos, res;
	scanf("%d ", &n);
	while (n > 0) {
		/* Leer la entrada y construir el array de frecuencias */
		scanf("%d ", &q);
		ultimapos = -1;
		repeticiones = 1;
		scanf("%d ", &valor);
		for (i = 1; i < n; ++i) {
			scanf("%d ", &a);
			if (a == valor) {
				repeticiones++;
			} else {
				for (j = 1; j <= repeticiones; ++j) {
					freq[ultimapos + j] = repeticiones;
					begin[ultimapos + j] = ultimapos + 1;
					end[ultimapos + j] = ultimapos + repeticiones;
				}
				ultimapos += repeticiones;
				repeticiones = 1;
				valor = a;
			}
		}
		for (j = 1; j <= repeticiones; ++j) {
			freq[ultimapos + j] = repeticiones;
			begin[ultimapos + j] = ultimapos + 1;
			end[ultimapos + j] = ultimapos + repeticiones;
		}

		/* Construir la sparse table */
		for (i = 0; i < n; ++i)
			M[i][0] = freq[i];
		for (j = 1; 1 << j <= n; ++j)
			for (i = 0; i + (1 << j) <= n; ++i)
				M[i][j] = max(M[i + (1 << (j-1))][j-1], M[i][j-1]);

		/* Consultas */
		while (q--) {
			scanf("%d %d ", &i, &j);
			i--, j--;
			res = 0;
			/* Acotado por ambos lados (repetición de un único número) */
			if (begin[i] < i && end[j] > j && begin[i] == begin[j]) {
				res = j - i + 1;
			} else {
				/* Acotado por la izquierda */
				if (begin[i] < i) {
					res = end[i] - i + 1;
					i = end[i] + 1;
				}
				/* Acotado por la derecha */
				if (end[j] > j) {
					res = max(j - begin[j] + 1, res);
					j = begin[j] - 1;
				}
				/* Intervalo completo */
				if (i <= j) {
					k = log(j - i + 1) / log(2.0);
					res = max(res, M[i][k]);
					res = max(res, M[j - (1<<k) + 1][k]);
				}
			}
			printf("%d\n", res);
		}

		scanf("%d ", &n);
	}

	return 0;
}
