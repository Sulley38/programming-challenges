#include <math.h>
#include <stdio.h>

int main() {
	unsigned int n, r;
	scanf("%u", &n);
	while (n != 0) {
		r = (long) sqrt(n);
		if (r*r == n)
			printf("yes\n");
		else
			printf("no\n");

		scanf("%u", &n);
	}

	return 0;
}

