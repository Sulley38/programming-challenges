#include <stdio.h>
#include <string.h>

static int ratas[1025][1025];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, d, n, x, y, size, bestx, besty, i, j;
	scanf("%d ", &t);
	while (t--) {
		memset(ratas, 0, sizeof ratas);
		bestx = besty = 0;
		scanf("%d %d ", &d, &n);
		while (n--) {
			scanf("%d %d %d ", &x, &y, &size);

			for (i = y - d; i <= y + d; ++i) {
				if (i >= 0 && i < 1025) {
					for (j = x - d; j <= x + d; ++j) {
						if (j >= 0 && j < 1025) {
							ratas[i][j] += size;
							if (ratas[i][j] > ratas[besty][bestx] || (ratas[i][j] == ratas[besty][bestx] && (j < bestx || (j == bestx && i < besty)))) {
								besty = i;
								bestx = j;
							}
						}
					}
				}
			}
		}

		printf("%d %d %d\n", bestx, besty, ratas[besty][bestx]);
	}

	return 0;
}
