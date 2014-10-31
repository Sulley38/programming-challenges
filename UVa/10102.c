#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char T[100][100];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int M, i, j, k, l, steps, res, dist;
	while (!feof(stdin)) {
		scanf("%d ", &M);
		for (i = 0; i < M; ++i)
			scanf("%s ", T[i]);
		/* Explorar el tablero completo */
		res = 0;
		for (i = 0; i < M; ++i) {
			for (j = 0; j < M; ++j) {
				/* Si es un 1, intentar ir a un 3 */
				if (T[i][j] == '1') {
					steps = 2 * M;
					for (k = 0; k < M; ++k) {
						for (l = 0; l < M; ++l) {
							dist = abs(i-k) + abs(j-l);
							if (T[k][l] == '3' && dist < steps)
								steps = dist;
						}
					}
					/* Quedarse con el máximo */
					if (steps > res)
						res = steps;
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
