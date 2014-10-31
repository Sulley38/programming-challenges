#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T, N, D, M[101];
	char S;
	int max, ans, caso, i, j;
	scanf("%d ", &T);
	for (caso = 1; caso <= T; ++caso) {
		scanf("%d %d ", &N, &D);
		ans = max = 0;
		M[0] = 0;
		j = 1;

		/* Check the stones */
		for (i = 1; i <= N; ++i) {
			scanf("%c-%d ", &S, &M[j]);
			/* Keep track of the longest leap of two stones (if there is any, leap of one otherwise) */
			if (j - 2 >= 0 && M[j] - M[j - 2] > max)
				max = M[j] - M[j - 2];
			else if (j - 1 >= 0 && M[j] - M[j - 1] > max)
				max = M[j] - M[j - 1];
			/* Reset if it is a big stone since it can be reused */
			if (S == 'B') {
				if (max > ans)
					ans = max;
				M[0] = M[j];
				max = j = 0;
			}
			j++;
		}

		/* Don't forget the right bank */
		if (j - 2 >= 0 && D - M[j - 2] > max)
			max = D - M[j - 2];
		else if (j - 1 >= 0 && D - M[j - 1] > max)
			max = D - M[j - 1];
		if (max > ans)
			ans = max;

		printf("Case %d: %d\n", caso, (N > 0) ? ans : D);
	}

	return 0;
}
