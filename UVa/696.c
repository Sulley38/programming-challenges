#include <stdio.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m, n, x, k, extra[4] = {0,2,4,4};
	while (scanf("%d %d\n", &m, &n) > 0 && (m != 0 || n != 0)) {
		if (m == 1) {
			k = n;
		} else if (n == 1) {
			k = m;
		} else if (m == 2) {
			k = 4*(n / 4) + extra[n%4];
		} else if (n == 2) {
			k = 4*(m / 4) + extra[m%4];
		} else {
			x = m * n;
			k = (x % 2 == 0) ? (x / 2) : (x / 2) + 1;
		}
		printf("%d knights may be placed on a %d row %d column board.\n", k, m, n);
	}
	return 0;
}
