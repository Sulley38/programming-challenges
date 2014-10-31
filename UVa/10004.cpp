#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
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
	int adj[200][200], deg[200], color[200];
	int n, l, a, b;
	while (scanf("%d %d ", &n, &l) > 1) {
		memset(deg, 0, n * sizeof(int));
		memset(color, -1, n * sizeof(int));
		/* Leer la entrada */
		for (int i = 0; i < l; ++i) {
			scanf("%d %d ", &a, &b);
			adj[a][deg[a]] = b;
			adj[b][deg[b]] = a;
			deg[a]++, deg[b]++;
		}
		color[0] = 0;
		/* BFS */
		bool posible = true;
		queue<int> cola;
		cola.push(0);
		while (!cola.empty() && posible) {
			a = cola.front();
			cola.pop();
			for (int i = 0; i < deg[a] && posible; ++i) {
				if (color[adj[a][i]] < 0) {
					color[adj[a][i]] = 1 - color[a];
					cola.push(adj[a][i]);
				} else if (color[adj[a][i]] == color[a]) {
					posible = false;
				}
			}
		}
		/* Dar el resultado */
		if (posible)
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}

	return 0;
}
