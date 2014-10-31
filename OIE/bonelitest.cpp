#include <cstdio>
#include <map>

using namespace std;

int main() {
/*#ifndef ONLINE_JUDGE
	#include <fstream>
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	int c, n, i, m;
	scanf("%d %d", &c, &n);
	while (c != 0 && n != 0) {
		int muestras[n];
		map<int,int,greater<int> > lista;

		for (i = 0; i < c; ++i) {
			scanf("%d", &muestras[i]);
			lista[muestras[i]]++;
		}
		m = lista.begin()->first;

		for (; i < n; ++i) {
			scanf("%d", &muestras[i]);
			lista[muestras[i]]++;
			if (lista[muestras[i-c]] == 1)
				lista.erase(muestras[i-c]);
			else
				lista[muestras[i-c]]--;
			m = min(m, lista.begin()->first);
		}

		printf("%d\n", m);
		scanf("%d %d", &c, &n);
	}

	return 0;
}
