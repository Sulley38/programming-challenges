#include <math.h>
#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m, n, t, b1, b2, maxb1, maxb2, beer, i, j;
	while (scanf("%d %d %d ", &m, &n, &t) > 0) {
		maxb1 = maxb2 = 0;
		beer = 10000;
		for (i = 0, b1 = 0; i <= t; i += m, b1++)
			for (j = 0, b2 = 0; i + j <= t; j += n, b2++)
				if (t - i - j < beer || (t - i - j == beer && b1 + b2 > maxb1 + maxb2)) {
					maxb1 = b1;
					maxb2 = b2;
					beer = t - i - j;
				}

		if (beer)
			printf("%d %d\n", maxb1 + maxb2, beer);
		else
			printf("%d\n", maxb1 + maxb2);
	}

	return 0;
}
