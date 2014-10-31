#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, n, caso;
	scanf("%d ", &t);
	int i, maxk, k, dif;
	for (caso = 1; caso <= t; ++caso) {
		scanf("%d ", &n);
		int R[n + 1];
		R[0] = maxk = 0;

		for (i = 1; i <= n; ++i) {
			scanf("%d ", &R[i]);
			dif = R[i] - R[i - 1];
			if (dif > maxk) {
				maxk = dif;
				k = maxk - 1;
			} else if (dif == k) {
				k--;
			} else if (dif > k) {
				k = -1;
			}
		}

		printf("Case %d: %d\n", caso, k < 0 ? maxk + 1 : maxk);
	}

	return 0;
}
