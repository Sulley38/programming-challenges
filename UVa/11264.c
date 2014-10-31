#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, n, V[1000], i, ans;
	long long sum;
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ", &n, &V[0]);

		ans = 1, sum = 1;
		for (i = 1; i < n; ++i) {
			scanf("%d ", &V[i]);
			if (sum < V[i])
				ans++;
			else
				sum -= V[i - 1];
			sum += V[i];
		}

		printf("%d\n", ans);
	}

	return 0;
}
