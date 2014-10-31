#include <algorithm>
#include <bitset>
#include <cmath>
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
typedef pair<int,int> pii;
typedef vector<int> vi;

pii bfs(vi *neighbours, const int N, const int from) {
	int target;
	pii p = pii(from, 0);
	queue<pii> cola;

	cola.push(p);
	vector<bool> visited(N);
	while(!cola.empty()) {
		p = cola.front();
		cola.pop();
		for (unsigned int i = 0; i < neighbours[p.first].size(); ++i) {
			target = neighbours[p.first][i];
			if (!visited[target]) {
				cola.push(pii(target, p.second + 1));
				visited[target] = true;
			}
		}
	}
	return p;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int C, N, A, B;
	int i;
	scanf("%d ", &C);
	while (C--) {
		/* read the input */
		scanf("%d ", &N);
		vi neighbours[N];
		for (i = 1; i < N; ++i) {
			scanf("%d %d ", &A, &B);
			neighbours[A].push_back(B);
			neighbours[B].push_back(A);
		}

		/* bfs from some node, get the farthest */
		pii p1 = bfs(neighbours, N, 0);
		/* bfs from that farthest node, get the farthest again */
		pii p2 = bfs(neighbours, N, p1.first);
		/* longest path is between those two nodes, ttl is half of the path */
		printf("%d\n", (p2.second % 2) ? (p2.second / 2 + 1) : (p2.second / 2));
	}

	return 0;
}
