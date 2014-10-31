#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	const int V[6] = {0, 1, 5, 10, 25, 50};
	long long P[6][30001];
	int n, i, j;

	for (i = 0; i < 6; ++i)
		P[i][0] = 1;
	for (j = 1; j < 30001; ++j)
		P[0][j] = 0;
	for (i = 1; i < 6; ++i)
		for (j = 1; j < 30001; ++j)
			if (j >= V[i])
				P[i][j] = P[i][j - V[i]] + P[i - 1][j];
			else
				P[i][j] = P[i - 1][j];

	while (scanf("%d ", &n) > 0) {
		if (P[5][n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", P[5][n], n);
	}

	return 0;
}
