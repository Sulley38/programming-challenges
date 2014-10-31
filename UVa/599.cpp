#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Contar árboles y vértices aislados
pair<int,int> analizar(vector<int> &V, vector< vector<int> > &E) {
	pair<int,int> r(0, 0);
	vector<bool> visitado(26, false);
	unsigned int i, j, k;
	for (i = 0; i < V.size(); ++i) {
		if (!visitado[V[i]]) {
			visitado[V[i]] = true;
			if (E[V[i]].size() > 0) {
				// Visitar en anchura los nodos del árbol
				queue<int> cola;
				cola.push(V[i]);
				while (!cola.empty()) {
					j = cola.front();
					cola.pop();
					for (k = 0; k < E[j].size(); ++k) {
						if (!visitado[E[j][k]]) {
							visitado[E[j][k]] = true;
							cola.push(E[j][k]);
						}
					}
				}
				r.first++;
			} else {
				// Vértice aislado
				r.second++;
			}
		}
	}
	return r;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i;
	char c, e1, e2, ast[256];
	scanf("%d ", &n);

	vector<int> point;
	vector< vector<int> > edge(26, vector<int>());
	pair<int,int> result;
	while (n--) {
		for (i = 0; i < 26; ++i)
			edge[i].clear();
		point.clear();
		// Leer aristas
		c = getchar();
		while (c != '*') {
			scanf("%c,%c) ", &e1, &e2);
			edge[e1 - 'A'].push_back(e2 - 'A');
			edge[e2 - 'A'].push_back(e1 - 'A');
			c = getchar();
		}
		fgets(ast, 256, stdin); // Descartar asteriscos
		// Leer vértices
		while (c != '\n' && c != EOF) {
			c = getchar();
			point.push_back(c - 'A');
			c = getchar();
		}

		result = analizar(point, edge);
		printf("There are %d tree(s) and %d acorn(s).\n", result.first, result.second);
	}

	return 0;
}
