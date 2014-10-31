#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, A, B, C, x, y, z, stop;
	scanf("%d ", &N);
	while (N--) {
		scanf("%d %d %d ", &A, &B, &C);
		stop = 0;
		for (x = -99; x < 100 && !stop; ++x)
			for (y = x + 1; y < 100 && !stop; ++y)
				for (z = y + 1; z < 100 && !stop; ++z)
					if (x + y + z == A && x*y*z == B && x*x + y*y + z*z == C)
						stop = 1;
		if (stop)
			printf("%d %d %d\n", x - 1, y - 1, z - 1);
		else
			puts("No solution.");
	}

	return 0;
}
