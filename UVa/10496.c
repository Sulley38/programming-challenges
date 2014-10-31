#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dist(a, b) (abs(X[a] - X[b]) + abs(Y[a] - Y[b]))

int p, X[11], Y[11];

int mindistance(int last, int visited) {
	if (visited == (1 << p) - 1) {
		return dist(last, 0);
	} else {
		/* Try each not visited point and solve recursively */
		int i, ans, minans = 100000;
		for (i = 1; i < p; ++i) {
			if ((visited & (1 << i)) == 0) {
				ans = mindistance(i, visited | (1 << i));
				if (ans + dist(last, i) < minans)
					minans = ans + dist(last, i);
			}
		}
		return minans;
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, m, n, b;
	int i;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d %d %d %d ", &m, &n, &X[0], &Y[0], &b);
		for (i = 1; i <= b; ++i)
			scanf("%d %d ", &X[i], &Y[i]);
		p = b + 1;
		printf("The shortest path has length %d\n", mindistance(0, 1));
	}
	return 0;
}
