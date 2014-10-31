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
	int c, l, m, cm, carga, movs;
	char lado[6];
	bool side; // True izquierda, false derecha
	queue<int> izq, der;

	scanf("%d ", &c);
	while (c--) {
		// Leer caso
		scanf("%d %d ", &l, &m);
		l *= 100;
		while (m--) {
			scanf("%d %s ", &cm, lado);
			if (lado[0] == 'l')
				izq.push(cm);
			else
				der.push(cm);
		}
		// Procesar colas
		side = true;
		movs = carga = 0;
		while (!izq.empty() || !der.empty()) {
			if (side) {
				// LADO IZQUIERDO
				while (!izq.empty() && carga + izq.front() <= l) {
					carga += izq.front();
					izq.pop();
				}
				side = false;
			} else {
				// LADO DERECHO
				while (!der.empty() && carga + der.front() <= l) {
					carga += der.front();
					der.pop();
				}
				side = true;
			}
			carga = 0;
			movs++;
		}

		printf("%d\n", movs);
	}

	return 0;
}
