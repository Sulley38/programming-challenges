#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, k, i;
	int dp[101][101];

	dp[0][0] = 1;
	for (i = 1; i <= 100; ++i) {
		dp[i][0] = 0;
		dp[0][i] = 1;
	}

	for (n = 1; n <= 100; ++n)
		for (k = 1; k <= 100; ++k) {
			dp[n][k] = 0;
			for (i = 0; i <= n; ++i)
				dp[n][k] = (dp[n][k] + dp[n - i][k - 1] % 1000000) % 1000000;
		}

	while (scanf("%d %d ", &n, &k) > 0 && n != 0)
		printf("%d\n", dp[n][k]);

	return 0;
}
