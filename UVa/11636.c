#include <math.h>
#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, caso = 0;
	double log2 = log(2.0);
	scanf("%d ", &n);
	while (n > 0) {
		printf("Case %d: %d\n", ++caso, (int)ceil(log(n) / log2));
		scanf("%d ", &n);
	}
	return 0;
}
