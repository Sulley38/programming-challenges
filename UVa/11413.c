#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, C[1000];

/* Returns true if the milk can be poured in m containers of at most 'ans' capacity */
int suitable(const int ans) {
	int i, filled = 0, count = 1;
	for (i = 0; i < n; ++i) {
		if (filled + C[i] <= ans) {
			filled += C[i];
		} else if (C[i] > ans) {
			return 0;
		} else {
			filled = C[i];
			count++;
			if (count > m) return 0;
		}
	}
	return 1;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i, low, high, mid;
	while (scanf("%d %d ", &n, &m) > 0) {
		low = high = 0;

		/* Read input and store limits for binary searching the answer */
		for (i = 0; i < n; ++i) {
			scanf("%d ", &C[i]);
			if (C[i] > low)
				low = C[i];
			high += C[i];
		}

		/* Binary search the answer */
		while (low < high) {
			mid = low + (high - low) / 2;
			if (suitable(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}

		printf("%d\n", low);
	}

	return 0;
}
