#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	unsigned int m, n, k, v, i;
	while (scanf("%d %d ", &n, &m) > 0) {
		vector< vector<int> > A(1000001, vector<int>());
		for (i = 0; i < n; ++i) {
			scanf("%d ", &v);
			A[v].push_back(i + 1);
		}
		while (m--) {
			scanf("%d %d ", &k, &v);
			if (A[v].size() >= k)
				printf("%d\n", A[v][k - 1]);
			else
				puts("0");
		}
	}

	return 0;
}
