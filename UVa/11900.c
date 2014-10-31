#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int test, caso, i, n, p, q, A[30], count;
	scanf("%d ", &test);
	for (caso = 1; caso <= test; caso++) {
		scanf("%d %d %d ", &n, &p, &q);
		for (i = 0; i < n; ++i)
			scanf("%d ", &A[i]);

		count = i = 0;
		while (i < n && p && q) {
			if (A[i] <= q) {
				count++;
				q -= A[i];
				p--;
			} else {
				q = 0;
			}
			i++;
		}

		printf("Case %d: %d\n", caso, count);
	}
	
	return 0;
}
