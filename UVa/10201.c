#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GasDist[101], GasPrice[101];
unsigned int MinCost[101][201];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, D, G;
	int i, l, k, dist, cost;
	char line[16];

	scanf("%d ", &T);
	while (T--) {
		G = 0;
		scanf("%d", &D);
		getchar();
		fgets(line, 16, stdin);
		while (!feof(stdin) && line[0] != '\n') {
			sscanf(line, "%d %d", &GasDist[G], &GasPrice[G]);
			G++;
			fgets(line, 16, stdin);
		}
		/* Add an extra point at the big city if there is not one */
		if (GasDist[G - 1] != D) {
			GasDist[G] = D, GasPrice[G] = -1;
			G++;
		}

		/* MinCost[i][j] = coste mínimo para alcanzar el punto i llegando con j litros en el depósito */
		memset(MinCost[0], -1, sizeof MinCost[0]);
		if (100 - GasDist[0] >= 0)
			MinCost[0][100 - GasDist[0]] = 0;
		for (i = 1; i < G; ++i) {
			for (l = 0; l <= 200; ++l) {
				MinCost[i][l] = -1;
				dist = GasDist[i] - GasDist[i - 1];
				if (l + dist <= 200) {
					for (k = 0; k <= l + dist; ++k) {
						if (MinCost[i - 1][k] != -1) {
							cost = MinCost[i - 1][k] + GasPrice[i - 1] * (l + dist - k);
							if (cost < MinCost[i][l])
								MinCost[i][l] = cost;
						}
					}
				}
			}
		}

		/* Look for the minimum cost to arrive to the big city */
		unsigned int ans = MinCost[G - 1][100];
		for (l = 101; l <= 200; ++l)
			if (MinCost[G - 1][l] < ans)
				ans = MinCost[G - 1][l];

		if (ans == -1)
			puts("Impossible");
		else
			printf("%d\n", ans);
		if (T) puts("");
	}

	return 0;
}
