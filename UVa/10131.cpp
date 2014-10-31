#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
vector<int> W, S, id;

bool comp(const int a, const int b) {
	return W[a] < W[b];
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int w, s, N = 0;
	// Leer y almacenar datos de entrada
	while (scanf("%d %d ", &w, &s) > 0) {
		W.push_back(w), S.push_back(s);
		id.push_back(N);
		N++;
	}
	// Ordenar elefantes por peso (creciente)
	sort(id.begin(), id.end(), comp);
	// longitud[i] = longitud de la secuencia decreciente más grande posible terminada en el elefante i-ésimo
	// padre[i] = elemento anterior a 'i' en la secuencia de longitud más grande posible...
	vector<int> longitud(N), padre(N);
	longitud[id[0]] = 1, padre[id[0]] = -1;
	int longitudmax = 0; // Id del último elemento de la secuencia de longitud máxima
	for (int i = 1; i < N; ++i) {
		longitud[id[i]] = 1, padre[id[i]] = -1;
		for (int j = 0; j < i; ++j) {
			if (W[id[i]] > W[id[j]] && S[id[i]] < S[id[j]] && longitud[id[j]] + 1 > longitud[id[i]]) {
				longitud[id[i]] = longitud[id[j]] + 1;
				padre[id[i]] = id[j];
			}
		}
		// Guardar el id de la secuencia más larga
		if (longitud[id[i]] > longitud[longitudmax])
			longitudmax = id[i];
	}
	// Construir el resultado a partir de los padres e imprimirlo
	vector<int> secuencia(longitud[longitudmax]);
	printf("%d\n", longitud[longitudmax]);
	int actual = longitudmax, i = 0;
	while (actual != -1) {
		secuencia[i++] = actual;
		actual = padre[actual];
	}
	for (int i = longitud[longitudmax] - 1; i >= 0; --i)
		printf("%d\n", secuencia[i]+1);

	return 0;
}
