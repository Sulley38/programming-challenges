#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int i, n, t, minimo, num_semaforos, h, m, s;
	vector<int> ciclos;
	while (cin >> n && n != 0) {
		ciclos.clear();
		ciclos.push_back(n);
		minimo = n;
		// Leer los ciclos y guardar el mínimo
		while (cin >> n && n != 0) {
			ciclos.push_back(n);
			if (n < minimo)
				minimo = n;
		}
		// Comprobar el color de todos los semáforos cada segundo
		num_semaforos = ciclos.size();
		for (t = minimo * 2; t <= 18000; ++t) {
			for (i = 0; i < num_semaforos; ++i) {
				n = t / (2 * ciclos[i]);
				if (t >= ciclos[i] * (2 * n + 1) - 5) // Semáforo en ámbar o rojo
					i = num_semaforos;
			}
			if (i == num_semaforos) // Todos verdes
				break;
		}
		// Imprimir resultado
		if (t == 18001) {
			puts("Signals fail to synchronise in 5 hours");
		} else {
			h = t / 3600;
			t %= 3600;
			m = t / 60;
			s = t % 60;
			printf("%02d:%02d:%02d\n", h, m, s);
		}
	}

	return 0;
}
