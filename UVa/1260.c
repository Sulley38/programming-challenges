#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, n, i, j;
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &n);
		int A[n], sum = 0;
		scanf("%d ", &A[0]);
		for (i = 1; i < n; ++i) {
			scanf("%d ", &A[i]);
			for (j = 0; j < i; ++j)
				if (A[j] <= A[i])
					sum++;
		}
		printf("%d\n", sum);
	}

	return 0;
}
