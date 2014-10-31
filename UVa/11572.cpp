#include <fstream>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int c, n, s, max;
	scanf("%d ", &c);

	queue<int> copos;
	set<int> cuenta;
	while (c--) {
		while (!copos.empty()) copos.pop();
		cuenta.clear();
		// Leer cada copo y encolar
		scanf("%d ", &n);
		max = 0;
		while (n--) {
			scanf("%d ", &s);
			if (cuenta.count(s)) {
				// Actualizar registro máximo
				if (int(copos.size()) > max)
					max = copos.size();
				// Vaciar cola por detrás hasta el repetido
				while (copos.front() != s) {
					cuenta.erase(copos.front());
					copos.pop();
				}
				copos.pop();
			} else {
				cuenta.insert(s);
			}
			copos.push(s);
		}

		if (int(copos.size()) > max)
			max = copos.size();
		printf("%d\n", max);
	}

	return 0;
}
