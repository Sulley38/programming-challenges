#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int x, r, c, m, n, i, j, size;
	char car;
	vector<int> ap(26);

	scanf("%d ", &x);
	for (int caso = 1; caso <= x; caso++) {
		scanf("%d %d %d %d ", &r, &c, &m, &n);
		fill(ap.begin(), ap.end(), 0);
		// Contar apariciones de caracteres
		for (i = 0; i < r; ++i) {
			for (j = 0; j < c; ++j) {
				car = getchar();
				ap[car - 'A']++;
			}
			car = getchar();
		}
		// Calcular tamaño
		sort(ap.begin(), ap.end(), greater<int>());
		size = i = 0;
		while (i < 26 && ap[0] == ap[i]) {
			size += m * ap[i];
			i++;
		}
		while (i < 26 && ap[i] > 0) {
			size += n * ap[i];
			i++;
		}

		printf("Case %d: %d\n", caso, size);
	}

	return 0;
}
