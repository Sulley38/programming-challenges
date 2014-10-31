#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	/* Precalcular sumas */
	int suma[100][100], i, j;
	suma[1][1] = 1;
	for (j = 3; j < 100; j += 2)
		suma[1][j] = suma[1][j-2] + j;
	for (i = 3; i < 100; i += 2)
		for (j = i; j < 100; j += 2)
			suma[i][j] = suma[i-2][j] - suma[i-2][i-2];

	int a, b, c, t;
	scanf("%d ", &t);
	for (c = 1; c <= t; ++c) {
		scanf("%d %d ", &a, &b);
		if (a % 2 == 0)
			a++;
		if (b % 2 == 0)
			b--;
		if (a < 100 && b > 0)
			printf("Case %d: %d\n", c, suma[a][b]);
		else
			printf("Case %d: 0\n", c);
	}
	return 0;
}
