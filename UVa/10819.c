#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MaxFav[i][j] = máximo valor que se puede obtener con los productos 1..i gastando exactamente j */
int MaxFav[101][10201];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m, n, P[101], F[101];
	int i, j, ans;

	MaxFav[0][0] = 0;
	for (j = 1; j < 10201; ++j)
		MaxFav[0][j] = -1;

	while (scanf("%d %d ", &m, &n) > 0) {
		for (i = 1; i <= n; ++i)
			scanf("%d %d ", &P[i], &F[i]);
		/* Fill DP table */
		for (i = 1; i <= n; ++i) {
			for (j = 0; j <= m + 200; ++j) {
				MaxFav[i][j] = MaxFav[i - 1][j];
				if (j - P[i] >= 0 && MaxFav[i - 1][j - P[i]] >= 0 && MaxFav[i - 1][j - P[i]] + F[i] > MaxFav[i - 1][j])
					MaxFav[i][j] = MaxFav[i - 1][j - P[i]] + F[i];
			}
		}
		/* Get best result */
		ans = 0;
		for (i = 1; i <= m; ++i)
			if (MaxFav[n][i] > ans)
				ans = MaxFav[n][i];
		if (m > 1800) {
			if (i <= 2000) i = 2001;
			for (; i <= m + 200; ++i)
				if (MaxFav[n][i] > ans)
					ans = MaxFav[n][i];
		}
		printf("%d\n", ans);
	}

	return 0;
}
