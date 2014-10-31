#include <math.h>
#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, a, b, c, i;
	while (scanf("%d ", &n) > 0 && n != 0 ) {
		a = b = c = i = 0;
		while (n > 0) {
			if (n & 1) {
				if (c & 1)
					b |= 1 << i, c <<= 1;
				else
					a |= 1 << i, c = (c << 1) | 1;
			}
			n >>= 1;
			i++;
		}
		printf("%d %d\n", a, b);
	}

	return 0;
}
