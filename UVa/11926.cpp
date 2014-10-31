#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char * hora = new char[1000001], conflicto; // 0 = Libre, 1 = Comienzo, 2 = Fin, 3 = Ocupado
	int m, n, inicio, fin, freq, i, j;
	scanf("%d %d ", &n, &m);
	while (m != 0 || n != 0) {
		conflicto = false;
		fill(hora, hora + 1000001, 0);
		// Tareas únicas
		for (i = 0; i < n; ++i) {
			scanf("%d %d ", &inicio, &fin);
			// Comprobar si hay colisión y marcar
			if (!conflicto) {
				if (hora[inicio] == 1 || hora[inicio] == 3) {
					conflicto = true;
				} else {
					hora[inicio] += 1;
					if (hora[fin] > 1) {
						conflicto = true;
					} else {
						hora[fin] += 2;
						for (j = inicio + 1; j < fin && !conflicto; ++j)
							if (hora[j] > 0)
								conflicto = true;
							else
								hora[j] = 3;
					}
				}
			}
		}
		// Tareas repetibles
		for (i = 0; i < m; ++i) {
			scanf("%d %d %d ", &inicio, &fin, &freq);
			// Comprobar si hay colisión y marcar
			if (!conflicto) {
				while (fin < 1000001 && !conflicto) {
					if (hora[inicio] == 1 || hora[inicio] == 3) {
						conflicto = true;
					} else {
						hora[inicio] += 1;
						if (hora[fin] > 1) {
							conflicto = true;
						} else {
							hora[fin] += 2;
							for (j = inicio + 1; j < fin && !conflicto; ++j)
								if (hora[j] > 0)
									conflicto = true;
								else
									hora[j] = 3;
						}
					}
					inicio += freq;
					fin += freq;
				}
				// últimos minutos
				if (!conflicto && inicio < 1000001) {
					if (hora[inicio] == 1 || hora[inicio] == 3) {
						conflicto = true;
					} else {
						hora[inicio] += 1;
						for (j = inicio + 1; j < 1000001 && !conflicto; ++j)
							if (hora[j] > 0)
								conflicto = true;
							else
								hora[j] = 3;
					}
				}
			}
		}

		if (conflicto)
			puts("CONFLICT");
		else
			puts("NO CONFLICT");
		scanf("%d %d ", &n, &m);
	}

	delete [] hora;
	return 0;
}
