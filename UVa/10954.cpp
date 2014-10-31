#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i, j, cost;
	while (scanf("%d ", &n) > 0 && n > 0) {
		priority_queue<int, vector<int>, greater<int> > num;
		for (i = 0; i < n; ++i) {
			scanf("%d ", &j);
			num.push(j);
		}

		cost = 0;
		while (!num.empty()) {
			i = num.top();
			num.pop();
			j = num.top();
			num.pop();
			cost += i + j;
			if (!num.empty())
				num.push(i + j);
		}

		printf("%d\n", cost);
	}

	return 0;
}
