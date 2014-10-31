#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, h[50], i, sum, height, moves, set = 0;
	while (scanf("%d ", &n) > 0 && n != 0) {
		sum = moves = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d ", &h[i]);
			sum += h[i];
		}
		height = sum / n;

		for (i = 0; i < n; ++i)
			if (h[i] > height)
				moves += h[i] - height;

		printf("Set #%d\n", ++set);
		printf("The minimum number of moves is %d.\n", moves);
		puts("");
	}
	return 0;
}
