#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int seq[50001];
int step[50001];

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int n, m, i, j, aux;

    /* Construir array auxliar: 1, 3, 6, 10, 15, 21, 28... */
    for (i = 1, j = 1; i <= 50000; ++i, j += i)
        step[i] = j;

    while (cin >> n >> m && n > 0) {
        for (j = 1; step[j] <= m; ++j) ; /* Esto se podría mejorar con búsqueda binaria, pero la lineal es suficiente para obtener AC */

        /* Desde 1 hasta n - j en orden creciente, desde n - j + 1 hasta n en orden inverso */
        /* Con esto conseguimos la secuencia más pequeña (orden lexicográfico) con exactamente 'step[j-1]' inversiones */
        for (i = 1; i <= n - j; ++i)
        	seq[i] = i;
        for ( ; i <= n; ++i)
        	seq[i] = n - (i - (n - j + 1));

        /* Simular el resto de inversiones una a una */
        m -= step[j - 1];
        for (i = n, j = n - j; m > 0; i--, m--) {
        	/* Intercambiar las posiciones i y j añade una inversión y se sigue teniendo la secuencia más pequeña */
            aux = seq[i];
			seq[i] = seq[j];
			seq[j] = aux;
        }

        /* Imprimir la secuencia */
        cout << seq[1];
        for (i = 2; i <= n; ++i)
            cout << ' ' << seq[i];
        cout << endl;
    }

	return 0;
}
