#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, a, f, i, j;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d ", &a, &f);
		while (f--) {
			for (i = 1; i <= a; ++i) {
				for (j = 0; j < i; ++j)
					putchar(i+'0');
				putchar('\n');
			}

			for (i = a - 1; i > 0; --i) {
				for (j = 0; j < i; ++j)
					putchar(i+'0');
				putchar('\n');
			}

			if (f > 0 || t > 0)
				putchar('\n');
		}
	}

	return 0;
}
