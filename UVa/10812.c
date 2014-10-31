#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, s, d;
	scanf("%d ", &n);
	while (n--) {
		scanf("%d %d ", &s, &d);
		if (d > s || (s - d) % 2 != 0)
			puts("impossible");
		else
			printf("%d %d\n", (s + d) / 2, (s - d) / 2);
	}

	return 0;
}
