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
	int N, M, book[10000], best1, best2;
	int i, j;
	while (scanf("%d ", &N) > 0) {
		for (i = 0; i < N; ++i)
			scanf("%d ", &book[i]);
		scanf("%d ", &M);
		sort(book, book + N);

		best1 = 0, best2 = 1000001;
		i = 0; j = N - 1;
		while (i < j) {
			if (book[i] + book[j] == M) {
				if (book[j] - book[i] < best2 - best1) {
					best1 = book[i];
					best2 = book[j];
				}
				i++, j--;
			} else if (book[i] + book[j] > M) {
				j--;
			} else {
				i++;
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", best1, best2);
	}

	return 0;
}
