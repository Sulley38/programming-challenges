#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m, S;
	int X[40], Y[40], C[301][301];
	scanf("%d ", &n);

	int i, j, k, ans;
	while (n--) {
		scanf("%d %d ", &m, &S);
		for (i = 0; i < m; ++i)
			scanf("%d %d ", &X[i], &Y[i]);
		/* Fill DP table */
		/* C[x][y] = número mínimo de monedas que suman x e y en valor convencional e IT, respectivamente */
		C[0][0] = 0;
		for (i = 0; i < 301; ++i) {
			for (j = 0; j < 301; ++j) {
				if (i == 0 && j == 0) continue;
				C[i][j] = 1 << 30;
				for (k = 0; k < m; ++k)
					if (i - X[k] >= 0 && j - Y[k] >= 0 && C[i - X[k]][j - Y[k]] + 1 < C[i][j])
						C[i][j] = C[i - X[k]][j - Y[k]] + 1;
			}
		}
		/* Search the pair (x,y) that x^2 + y^2 = S^2 with min C[x][y] */
		ans = 1 << 30;
		for (i = 0; i < 301; ++i)
			for (j = 0; j < 301; ++j)
				if (i*i + j*j == S*S && C[i][j] < ans)
					ans = C[i][j];

		if (ans == 1 << 30)
			puts("not possible");
		else
			printf("%d\n", ans);
	}

	return 0;
}
