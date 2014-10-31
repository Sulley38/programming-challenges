#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, n, i, j, k, pop[5][5];
	scanf("%d ", &t);
	int I[5], J[5], Opt[5], suma, minsuma, dist, dist2;
	while (t--) {
		memset(pop, 0, sizeof pop);
		/* Leer la entrada */
		scanf("%d ", &n);
		for (k = 0; k < n; ++k) {
			scanf("%d %d ", &i, &j);
			scanf("%d ", &pop[i][j]);
		}
		/* Comprobar todas las posibles combinaciones de tiendas */
		minsuma = 10000000;
		for (I[0] = 0; I[0] < 5; ++I[0])
		for (J[0] = 0; J[0] < 5; ++J[0])
			for (I[1] = I[0], J[1] = J[0] + 1; I[1] < 5; ++I[1], J[1] = 0)
			for (; J[1] < 5; ++J[1])
				for (I[2] = I[1], J[2] = J[1] + 1; I[2] < 5; ++I[2], J[2] = 0)
				for (; J[2] < 5; ++J[2])
					for (I[3] = I[2], J[3] = J[2] + 1; I[3] < 5; ++I[3], J[3] = 0)
					for (; J[3] < 5; ++J[3])
						for (I[4] = I[3], J[4] = J[3] + 1; I[4] < 5; ++I[4], J[4] = 0)
						for (; J[4] < 5; ++J[4]) {
							suma = 0;
							for (i = 0; i < 5; ++i)
							for (j = 0; j < 5; ++j) {
								/* Calcular la distancia a la oficina más cercana y sumarla */
								dist = abs(I[0] - i) + abs(J[0] - j);
								dist2 = abs(I[1] - i) + abs(J[1] - j);
								if (dist2 < dist) dist = dist2;
								dist2 = abs(I[2] - i) + abs(J[2] - j);
								if (dist2 < dist) dist = dist2;
								dist2 = abs(I[3] - i) + abs(J[3] - j);
								if (dist2 < dist) dist = dist2;
								dist2 = abs(I[4] - i) + abs(J[4] - j);
								if (dist2 < dist) dist = dist2;
								suma += dist * pop[i][j];
							}
							/* Guardar el óptimo */
							if (suma < minsuma) {
								minsuma = suma;
								Opt[0] = I[0] * 5 + J[0];
								Opt[1] = I[1] * 5 + J[1];
								Opt[2] = I[2] * 5 + J[2];
								Opt[3] = I[3] * 5 + J[3];
								Opt[4] = I[4] * 5 + J[4];
							}
						}
		/* Dar el resultado */
		printf("%d %d %d %d %d\n", Opt[0], Opt[1], Opt[2], Opt[3], Opt[4]);
	}

	return 0;
}
