#include <stdio.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int c;
	while ((c = getchar()) != EOF) {
		if (c >= 32) c -= 7;
		putchar(c);
	}

	return 0;
}
