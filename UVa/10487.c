#include <stdio.h>
#include <stdlib.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m, q, i, j, caso = 0;
	while (scanf("%d ", &n) > 0 && n > 0) {
		int A[n];
		for (i = 0; i < n; ++i)
			scanf("%d ", &A[i]);
		scanf("%d ", &m);
		printf("Case %d:\n", ++caso);
		while (m--) {
			scanf("%d ", &q);
			int closest = A[0] + A[1];
			for (i = 2; i < n; ++i)
				for (j = 0; j < i; ++j)
					if (abs(A[i] + A[j] - q) < abs(closest - q))
						closest = A[i] + A[j];
			printf("Closest sum to %d is %d.\n", q, closest);
		}
	}

	return 0;
}
