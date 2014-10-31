#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso, casos, N;
	int W[MAX], H[MAX], LIS[MAX], LDS[MAX];
	int maxLIS, maxLDS, i, j;
	scanf("%d ", &casos);
	for (caso = 1; caso <= casos; ++caso) {
		/* Leer la entrada */
		scanf("%d ", &N);
		for (i = 0; i < N; ++i)
			scanf("%d ", &H[i]);
		for (i = 0; i < N; ++i)
			scanf("%d ", &W[i]);
		/* Procesar LIS y LDS terminados en el edificio i */
		maxLIS = maxLDS = 0;
		for (i = 0; i < N; ++i) {
			LIS[i] = LDS[i] = W[i];
			for (j = 0; j < i; ++j) {
				if (H[j] < H[i] && LIS[i] < LIS[j] + W[i])
					LIS[i] = LIS[j] + W[i];
				if (H[j] > H[i] && LDS[i] < LDS[j] + W[i])
					LDS[i] = LDS[j] + W[i];
			}
			if (LIS[i] > maxLIS) maxLIS = LIS[i];
			if (LDS[i] > maxLDS) maxLDS = LDS[i];
		}
		/* Dar el resultado */
		if (maxLIS >= maxLDS)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", caso, maxLIS, maxLDS);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", caso, maxLDS, maxLIS);
	}


	return 0;
}
