#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector< vector<int> > caja, maximo;
vector<bool> recorridos;

// True si a entra en b
bool menor(const int &a, const int &b) {
	for (unsigned int i = 0; i < caja[a].size(); ++i)
		if (caja[a][i] >= caja[b][i])
			return false;
	return true;
}
// Recorre en busca de cajas que entren en nodo
void recorrer(int nodo) {
	if (!recorridos[nodo]) {
		for (int i = 0; i < k; ++i) {
			if (menor(i, nodo)) {
				recorrer(i);
				if (maximo[i].size() > maximo[nodo].size()) {
					maximo[nodo] = maximo[i];
				}
			}
		}
		maximo[nodo].push_back(nodo);
		recorridos[nodo] = true;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int i, j, maxLongitud;
	while (cin >> k >> n) {
		caja = vector< vector<int> >(k, vector<int>(n));
		for (i = 0; i < k; ++i) {
			for (j = 0; j < n; ++j)
				cin >> caja[i][j];
			sort(caja[i].begin(), caja[i].end());
		}

		maxLongitud = 0; // Nodo desde el que se obtiene la cadena más larga
		recorridos = vector<bool>(k); // Nodos recorridos
		maximo = vector< vector<int> >(k, vector<int>()); // Cadena más larga desde cada nodo
		for (i = 0; i < k; ++i) {
			recorrer(i);
			if (maximo[i].size() > maximo[maxLongitud].size())
				maxLongitud = i;
		}

		cout << maximo[maxLongitud].size() << endl;
		for (i = 0; i < int(maximo[maxLongitud].size() - 1); ++i)
			cout << maximo[maxLongitud][i]+1 << " ";
		cout << maximo[maxLongitud][i]+1 << endl;

	}
	return 0;
}
