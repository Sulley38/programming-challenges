#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))
#define INF 10000000

int R[10], C[10];
int Cost[10][10], Product[10][10];
int First[10], Last[10];

int solve(int l, int r) {
	if (Cost[l][r] != -1) {
		/* Previously calculated */
		return Cost[l][r];
	}
	if (l == r) {
		/* No product needs to be performed */
		return Cost[l][r] = 0;
	}
	if (l == r - 1) {
		/* Simple product of two matrices */
		return Cost[l][r] = R[l] * C[l] * C[r];
	}
	/* Choose a product among all possibilities */
	int minCost = R[l] * C[l] * C[r] + solve(l + 1, r), minM = l;
	int m, cost;
	for (m = l + 1; m < r; ++m) {
		cost = R[l] * C[m] * C[r] + solve(l, m) + solve(m + 1, r);
		if (cost < minCost) {
			minCost = cost;
			minM = m;
		}
	}
	Product[l][r] = minM;
	return Cost[l][r] = minCost;
}

void getProducts(int l, int r) {
	if (l == r) return;
	First[l]++, Last[r]++;
	if (l < r - 1) {
		getProducts(l, Product[l][r]);
		getProducts(Product[l][r] + 1, r);
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int Case = 1, N;
	int i, j;
	scanf("%d ", &N);
	while (N > 0) {
		memset(Cost, -1, sizeof Cost);
		for (i = 0; i < N; ++i) {
			scanf("%d %d ", &R[i], &C[i]);
			First[i] = 0, Last[i] = 0;
		}

		solve(0, N - 1);
		getProducts(0, N - 1);

		printf("Case %d: ", Case++);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < First[i]; ++j)
				putchar('(');
			printf("A%d", i + 1);
			for (j = 0; j < Last[i]; ++j)
				putchar(')');
			if (i != N - 1)
				printf(" x ");
		}
		putchar('\n');

		scanf("%d ", &N);
	}

	return 0;
}
