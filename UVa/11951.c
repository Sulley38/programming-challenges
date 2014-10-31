#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso, t, n, m, money, i, j, k;
	int P[100][100];
	scanf("%d ", &t);
	for (caso = 1; caso <= t; caso++) {
		scanf("%d %d %d ", &n, &m, &money);
		for (j = 0; j < m; ++j)
			scanf("%d ", &P[0][j]);
		for (i = 1; i < n; ++i)
			for (j = 0; j < m; ++j) {
				scanf("%d ", &P[i][j]);
				P[i][j] += P[i-1][j];
			}

		/* Calculate max area checking that cost < money (Kadane 2D) */
		int maxarea = 0, maxcost = 0, area, cost, begin;
		for (i = 0; i < n; ++i) {
			for (j = i; j < n; ++j) {
				cost = begin = 0;
				for (k = 0; k < m; ++k) {
					cost += P[j][k] - ((i > 0) ? P[i-1][k] : 0);
					/* Quitar por la izquierda si se pasa de presupuesto */
					while (cost > money) {
						cost -= P[j][begin] - ((i > 0) ? P[i-1][begin] : 0);
						begin++;
					}
					/* Guardar el área máxima, y en caso de empate, el coste mínimo */
					area = (j-i+1) * (k-begin+1);
					if (area > maxarea) {
						maxarea = area;
						maxcost = cost;
					} else if (area == maxarea && cost < maxcost) {
						maxcost = cost;
					}
				}
			}
		}

		printf("Case #%d: %d %d\n", caso, maxarea, maxcost);
	}

	return 0;
}
