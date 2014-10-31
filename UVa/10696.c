#include <stdio.h>
#include <stdlib.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char buf[10];
	int N;
	gets(buf);
	while (buf[0] != '0') {
		N = atoi(buf);
		if (N > 100)
			printf("f91(%d) = %d\n", N, N - 10);
		else
			printf("f91(%d) = 91\n", N);
		gets(buf);
	}

	return 0;
}
