#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, M, Q, L, U;
	int q, i, j, low, high, mid;
	int lower, ans;
	while (scanf("%d %d ", &N, &M) && N > 0) {
		int H[N][M];
		for (i = 0; i < N; ++i)
			for (j = 0; j < M; ++j)
				scanf("%d ", &H[i][j]);
		scanf("%d ", &Q);
		for (q = 0; q < Q; ++q) {
			scanf("%d %d ", &L, &U);
			ans = 0;
			/* Search a possible top-left square row by row */
			for (i = 0; i < N; ++i) {
				lower = (int) (lower_bound(H[i], H[i] + M, L) - H[i]);
				if (lower < M && H[i][lower] <= U) {
					low = 0, high = min(N - i - 1, M - lower - 1);
					/* Binary search on the diagonal for the greatest element <= U, leaves the result in high */
					while (low < high && high + 1 > ans) {
						mid = (low + high) / 2 + 1;
						if (H[i + mid][lower + mid] > U) {
							high = mid - 1;
						} else {
							low = mid;
						}
					}
					/* Keep track of the best answer so far */
					if (high + 1 > ans)
						ans = high + 1;
				}
			}
			printf("%d\n", ans);
		}
		puts("-");
	}

	return 0;
}
