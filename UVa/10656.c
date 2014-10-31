#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, A, first, i;
	scanf("%d ", &N);
	while (N > 0) {
		first = 1;
		for (i = 0; i < N; ++i) {
			scanf("%d ", &A);
			if (A > 0) {
				if (first) {
					printf("%d", A);
					first = 0;
				} else {
					printf(" %d", A);
				}
			}
		}
		if (first)
			puts("0");
		else
			puts("");
		scanf("%d ", &N);
	}

	return 0;
}
