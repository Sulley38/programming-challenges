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
	int n, first = 1, rep, ans, i, j;
	int bag[10000];
	scanf("%d ", &n);
	while (n > 0) {
		if (!first) puts("");

		for (i = 0; i < n; ++i)
			scanf("%d ", &bag[i]);
		sort(bag, bag + n);

		ans = rep = 1;
		for (i = 1; i < n; ++i) {
			/* Number of pieces: number of appearances of the most repeated size */
			if (bag[i] == bag[i - 1]) {
				rep++;
			} else {
				ans = max(ans, rep);
				rep = 1;
			}
		}
		ans = max(ans, rep);

		/* Print each of the pieces */
		printf("%d\n", ans);
		for (i = 0; i < ans; ++i) {
			printf("%d", bag[i]);
			for (j = i + ans; j < n; j += ans)
				printf(" %d", bag[j]);
			putchar('\n');
		}

		scanf("%d ", &n);
		first = 0;
	}

	return 0;
}
