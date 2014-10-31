#include <math.h>
#include <stdio.h>

#define max(a,b) (b > a ? b : a)

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, c, i, j, maxp;
	while (scanf("%d ", &n) > 0) {
		/* Esquinas */
		c = pow(2, n);
		/* Leer sus pesos */
		int w[c], p[c];
		for (i = 0; i < c; ++i)
			scanf("%d ", &w[i]);
		/* Calcular potencias */
		for (i = 0; i < c; ++i) {
			p[i] = 0;
			for (j = 0; j < n; ++j)
				p[i] += w[i ^ (1 << j)];
		}
		/* Buscar pareja de potencia máxima */
		maxp = 0;
		for (i = 0; i < c; ++i)
			for (j = 0; j < n; ++j)
				maxp = max(maxp, p[i] + p[i ^ (1 << j)]);

		printf("%d\n", maxp);
	}
	return 0;
}
