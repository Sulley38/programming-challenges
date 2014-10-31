#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	long long int N;
	scanf("%lld ", &N);
	while (N >= 0) {
		printf("%lld\n", (N * (N + 1)) / 2 + 1);
		scanf("%lld ", &N);
	}

	return 0;
}
