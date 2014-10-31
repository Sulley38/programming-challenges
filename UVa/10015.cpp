#ifdef TESTING
#include <fstream>
#endif
#include <iostream>
#include <vector>

using namespace std;

#define MAXIMO 1000000
#define CANTIDAD 3500

void criba(vector<int> &primos) {
	vector<bool> es_primo(MAXIMO, true);
	int i, j;
	/* Descartar números */
	for (i = 2; i < MAXIMO; ++i)
		if (es_primo[i])
			for (j = 2; i * j < MAXIMO; ++j)
				es_primo[i * j] = false;
	/* Contar resultado */
	j = 2;
	for (i = 0; j < MAXIMO && i < CANTIDAD; ++i) {
		while (j < MAXIMO && !es_primo[j]) ++j;
		primos[i] = j;
		++j;
	}
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	vector<int> primos(CANTIDAD);
	criba(primos);

	int n, p, i;
	while (cin >> n && n != 0) {
		for (p = 0, i = 1; i <= n; ++i)
			p = (p + primos[n - i]) % i;

		cout << p + 1 << endl;
	}

	return 0;
}
