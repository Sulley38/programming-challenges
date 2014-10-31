#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, a, b;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d ", &a, &b);
		if (a > b)
			puts(">");
		else if (a < b)
			puts("<");
		else
			puts("=");
	}
	return 0;
}
