#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 999
#define BIG 2147483647

typedef pair<int,int> PII;

int maze[MAX][MAX], coste[MAX][MAX];
bool marca[MAX][MAX];

struct comp {
	bool operator() (const PII &a, const PII &b) const {
		return coste[a.first][a.second] > coste[b.first][b.second];
	}
};

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, M, N, i, j;
	PII p;
	// Leer datos de entrada
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d ",&N, &M);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < M; ++j) {
				scanf("%d ", &maze[i][j]);
				coste[i][j] = BIG;
				marca[i][j] = false;
			}
		}
		// Dijkstra desde el (0,0)
		coste[0][0] = maze[0][0];
		priority_queue<PII, vector<PII>, comp> cola;
		cola.push(PII(0, 0));
		while (!cola.empty()) {
			p = cola.top();
			cola.pop();
			i = p.first;
			j = p.second;
			if (!marca[i][j]) {
				marca[i][j] = true;
				// Comprobar las cuatro direcciones
				if (i > 0 && !marca[i-1][j] && coste[i-1][j] > coste[i][j] + maze[i-1][j]) {
					coste[i-1][j] = coste[i][j] + maze[i-1][j];
					cola.push(PII(i-1, j));
				}
				if (i+1 < N && !marca[i+1][j] && coste[i+1][j] > coste[i][j] + maze[i+1][j]) {
					coste[i+1][j] = coste[i][j] + maze[i+1][j];
					cola.push(PII(i+1, j));
				}
				if (j > 0 && !marca[i][j-1] && coste[i][j-1] > coste[i][j] + maze[i][j-1]) {
					coste[i][j-1] = coste[i][j] + maze[i][j-1];
					cola.push(PII(i, j-1));
				}
				if (j+1 < M && !marca[i][j+1] && coste[i][j+1] > coste[i][j] + maze[i][j+1]) {
					coste[i][j+1] = coste[i][j] + maze[i][j+1];
					cola.push(PII(i, j+1));
				}
			}
		}
		printf("%d\n", coste[N-1][M-1]);
	}

	return 0;
}
