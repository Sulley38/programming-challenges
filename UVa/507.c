#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))
#define INF 10000000

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int b, r, s, A[20000];
	int begin, maxbegin, maxend, sum, maxsum, i;
	scanf("%d ", &b);
	for (r = 1; r <= b; ++r) {
		scanf("%d ", &s);
		begin = sum = 0;
		maxbegin = -2, maxsum = maxend = -1;
		for (i = 0; i < s - 1; ++i) {
			scanf("%d ", &A[i]);
			sum += A[i];
			if (sum < 0) {
				sum = 0;
				begin = i + 1;
			} else if (sum > maxsum) {
				maxbegin = begin;
				maxend = i + 1;
				maxsum = sum;
			} else if (sum == maxsum && i + 1 - begin > maxend - maxbegin) {
				maxbegin = begin;
				maxend = i + 1;
			}
		}

		if (maxbegin >= 0)
			printf("The nicest part of route %d is between stops %d and %d\n", r, maxbegin + 1, maxend + 1);
		else
			printf("Route %d has no nice parts\n", r);
	}

	return 0;
}
