#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp (const void *a, const void *b) {
	return (*(int*)a) - (*(int*)b);
}

int cmpInv (const void *a, const void *b) {
	return (*(int*)b) - (*(int*)a);
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, D, R, Mor[100], Eve[100], Assigned[100];
	int i;
	while (scanf("%d %d %d ", &N, &D, &R) > 0 && N > 0) {
		memset(Assigned, 0, sizeof Assigned);
		for (i = 0; i < N; ++i)
			scanf("%d ", &Mor[i]);
		for (i = 0; i < N; ++i)
			scanf("%d ", &Eve[i]);

		qsort(Mor, N, sizeof(int), cmp);
		qsort(Eve, N, sizeof(int), cmpInv);

		int extra = 0;
		for (i = 0; i < N; ++i) {
			if (Mor[i] + Eve[i] > D)
				extra += (Mor[i] + Eve[i] - D) * R;
		}

		printf("%d\n", extra);
	}

	return 0;
}
