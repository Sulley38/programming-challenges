#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int w;
	scanf("%d ", &w);
	if (w % 2 || w == 2)
		puts("NO");
	else
		puts("YES");
	return 0;
}
