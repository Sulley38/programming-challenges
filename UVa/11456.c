#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, n, W[2000];
	int LIS[2000], LDS[2000], maxlength;
	int i, j;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d ", &n);
		for (i = 0; i < n; ++i)
			scanf("%d ", &W[i]);
		/* LIS empezando en el vagón i */
		for (i = n - 1; i >= 0; --i) {
			LIS[i] = 1;
			for (j = i + 1; j < n; ++j)
				if (W[j] > W[i] && LIS[j] + 1 > LIS[i])
					LIS[i] = LIS[j] + 1;
		}
		/* LDS empezando en el vagón i */
		for (i = n - 1; i >= 0; --i) {
			LDS[i] = 1;
			for (j = i + 1; j < n; ++j)
				if (W[j] < W[i] && LDS[j] + 1 > LDS[i])
					LDS[i] = LDS[j] + 1;
		}
		/* Buscar el vagón inicial que dé la mejor combinación LIS+LDS */
		maxlength = 0;
		for (i = 0; i < n; ++i)
			if (LIS[i] + LDS[i] - 1 > maxlength)
				maxlength = LIS[i] + LDS[i] - 1;
		printf("%d\n", maxlength);
	}

	return 0;
}
