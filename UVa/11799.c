#include <stdio.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, i, n, t, c, maxc;
	scanf("%d", &t);
	for (a = 1; a <= t; ++a) {
		scanf("%d %d", &n, &maxc);
		for (i = 1; i < n; ++i) {
			scanf("%d", &c);
			if (c > maxc)
				maxc = c;
		}
		printf("Case %d: %d\n", a, maxc);
	}

	return 0;
}
