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
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;

vii adj;
vi num, low;
vi parent;
vi pidgeon;
vb visited;
int cuenta, rootChildren;

/* num[i] = posición en la que se visita por primera vez el nodo i */
/* low[i] = mínimo num alcanzable desde el nodo i y sus hijos */
void dfs(int u) {
	num[u] = low[u] = cuenta++;
	visited[u] = true;
	for (unsigned int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!visited[v]) {
			if (u == 0) rootChildren++;
			parent[v] = u;
			dfs(v);
			/* Si desde v no llego a ningún padre de u, u es punto articulación */
			if (low[v] >= num[u])
				pidgeon[u]++;
			/* Actualizar el nodo más temprano que alcanzo desde u: el que pueda alcanzar desde v */
			low[u] = min(low[u], low[v]);
		} else if (parent[u] != v) {
			/* Actualizar el nodo más temprano que alcanzo desde u: el propio v */
			low[u] = min(low[u], num[v]);
		}
	}
}

bool cmp (const int a, const int b) {
	if (pidgeon[a] == pidgeon[b])
		return a < b;
	return pidgeon[a] > pidgeon[b];
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m, x, y;
	cin >> n >> m;
	while (n > 0) {
		adj = vii(n, vi());
		num = vi(n);
		low = vi(n);
		parent = vi(n);
		pidgeon = vi(n, 1);
		visited = vb(n);

		cin >> x >> y;
		while (x >= 0) {
			adj[x].push_back(y);
			adj[y].push_back(x);
			cin >> x >> y;
		}

		rootChildren = cuenta = 0;
		parent[0] = -1;
		dfs(0);
		pidgeon[0] = rootChildren;

		vector<int> in(n);
		for (int i = 0; i < n; ++i)
			in[i] = i;
		sort(in.begin(), in.end(), cmp);

		for (int i = 0; i < m; ++i)
			cout << in[i] << " " << pidgeon[in[i]] << endl;
		cout << endl;

		cin >> n >> m;
	}

}
