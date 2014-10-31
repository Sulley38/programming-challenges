#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n, i, j, k;
	cin >> n;

	// Cuanto más negativo, tira a ser ligera. Cuanto más positivo, a ser pesada
	int moneda[12];
	bool esbuena[12];
	string p[3][3];
	while (n--) {
		cin >> p[0][0] >> p[0][1] >> p[0][2] >> p[1][0] >> p[1][1] >> p[1][2] >> p[2][0] >> p[2][1] >> p[2][2];

		for (i = 0; i < 12; ++i) {
			moneda[i] = 0;
			esbuena[i] = 0;
		}

		for (i = 0; i < 3; ++i) {
			k = p[i][0].size();
			if (p[i][2] == "even") {
				// Todas son buenas
				for (j = 0; j < k; ++j) {
					esbuena[p[i][0][j]-'A'] = 1;
					esbuena[p[i][1][j]-'A'] = 1;
				}
			} else if (p[i][2] == "up") {
				// Las de la izquierda pueden ser pesadas o la derecha ligeras
				for (j = 0; j < k; ++j) {
					moneda[p[i][0][j]-'A']++;
					moneda[p[i][1][j]-'A']--;
				}
			} else {
				// Las de la izquierda pueden ser ligeras o la derecha pesadas
				for (j = 0; j < k; ++j) {
					moneda[p[i][0][j]-'A']--;
					moneda[p[i][1][j]-'A']++;
				}
			}
		}

		// Buscar la que no sea buena y que tenga más votos
		int min = *min_element(moneda, moneda+12), max = *max_element(moneda, moneda+12);
		int extremo = abs(min) > abs(max) ? abs(min) : abs(max);
		for (i = 0; i < 12; ++i) {
			if (esbuena[i] == 0 && abs(moneda[i]) == extremo) {
				if (moneda[i] < 0)
					cout << (char)(i + 'A') << " is the counterfeit coin and it is light." << endl;
				else
					cout << (char)(i + 'A') << " is the counterfeit coin and it is heavy." << endl;
			}
		}
	}

	return 0;
}
