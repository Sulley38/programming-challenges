#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int k, n, m, x, y;
	while (scanf("%d ", &k) > 0 && k != 0) {
		scanf("%d %d ", &m, &n);
		while (k--) {
			scanf("%d %d ", &x, &y);
			if (x == m || y == n)
				puts("divisa");
			else if (x < m && y < n)
				puts("SO");
			else if (x < m && y > n)
				puts("NO");
			else if (x > m && y < n)
				puts("SE");
			else
				puts("NE");
		}
	}
	return 0;
}
