#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

int MinWaste[601][601];

int main(void) {
	int t, N, W, H;
	int Wi[200], Hi[200];
	int i, j, k;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d %d ", &W, &H, &N);
		for (i = 0; i < N; ++i)
			scanf("%d %d ", &Wi[i], &Hi[i]);

		for (i = 0; i <= W; ++i) {
			for (j = 0; j <= H; ++j) {
				MinWaste[i][j] = i * j;
				for (k = 0; k < N; ++k) {
					if (i - Wi[k] >= 0 && j - Hi[k] >= 0) {
						MinWaste[i][j] = MIN(MinWaste[i][j], MinWaste[i - Wi[k]][Hi[k]] + MinWaste[i][j - Hi[k]]);
						MinWaste[i][j] = MIN(MinWaste[i][j], MinWaste[Wi[k]][j - Hi[k]] + MinWaste[i - Wi[k]][j]);
					}
				}
			}
		}

		printf("%d\n", MinWaste[W][H]);
	}

	return 0;
}
