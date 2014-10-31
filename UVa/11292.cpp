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
	int n, m, ans;
	int i, j;
	scanf("%d %d ", &n, &m);
	while (n > 0 || m > 0) {
		// Read the input data
		int head[n], height[m];
		for (i = 0; i < n; ++i)
			scanf("%d ", &head[i]);
		for (i = 0; i < m; ++i)
			scanf("%d ", &height[i]);

		if (n > m) {
			puts("Loowater is doomed!");
		} else {
			// Sort the diameters and heights
			sort(head, head + n);
			sort(height, height + m);
			ans = 0;
			// Assign each head to the lowest knight possible
			j = 0;
			for (i = 0; i < n; ++i, ++j) {
				while (j < m && height[j] < head[i]) j++;
				if (j == m) break;
				ans += height[j];
			}
			// Check if all heads have been assigned
			if (i == n)
				printf("%d\n", ans);
			else
				puts("Loowater is doomed!");
		}

		scanf("%d %d ", &n, &m);
	}

	return 0;
}
