#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int c, n, t, m, arrive, tiempo, cruzado, carga, i;
	bool side = true; // True izquierda, false derecha
	queue< pair<int,int> > izq, der;
	char lado[6];

	scanf("%d ", &c);
	while (c--) {
		// Leer caso
		scanf("%d %d %d ", &n, &t, &m);
		for (i = 0; i < m; ++i) {
			scanf("%d %s ", &arrive, lado);
			if (lado[0] == 'l')
				izq.push(make_pair(i, arrive));
			else
				der.push(make_pair(i, arrive));
		}

		// Procesar colas
		vector<int> llegada(m);
		side = true;
		tiempo = cruzado = carga = 0;
		while (cruzado < m) {
			if (side) {
				// LADO IZQUIERDO
				if (izq.empty() || izq.front().second > tiempo) {
					// Si hay esperando al otro lado, cruzar.
					if (!der.empty() && der.front().second <= tiempo) {
						tiempo += t;
						side = false;
					}
					// Si no hay nada a ambos lados, esperar.
					else {
						if (izq.empty())
							tiempo = der.front().second;
						else if (der.empty())
							tiempo = izq.front().second;
						else
							tiempo = min(izq.front().second, der.front().second);
					}
				} else {
					// Cargar todo lo posible, hasta n o hasta que no haya más
					while (!izq.empty() && carga < n && izq.front().second <= tiempo) {
						llegada[izq.front().first] = tiempo + t;
						izq.pop();
						cruzado++;
						carga++;
					}
					tiempo += t;
					side = false;
					carga = 0;
				}
			} else {
				// LADO DERECHO
				if (der.empty() || der.front().second > tiempo) {
					// Si hay esperando al otro lado, cruzar.
					if (!izq.empty() && izq.front().second <= tiempo) {
						tiempo += t;
						side = true;
					}
					// Si no hay nada a ambos lados, esperar.
					else {
						if (izq.empty())
							tiempo = der.front().second;
						else if (der.empty())
							tiempo = izq.front().second;
						else
							tiempo = min(izq.front().second, der.front().second);
					}
				} else {
					// Cargar todo lo posible, hasta n o hasta que no haya más
					while (!der.empty() && carga < n && der.front().second <= tiempo) {
						llegada[der.front().first] = tiempo + t;
						der.pop();
						cruzado++;
						carga++;
					}
					tiempo += t;
					side = true;
					carga = 0;
				}
			}
		}

		// Imprimir tiempos en orden
		for (i = 0; i < m; ++i)
			printf("%d\n", llegada[i]);
		if (c)
			puts("");
	}

	return 0;
}
