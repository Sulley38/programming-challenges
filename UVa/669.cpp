#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> PII; // first: fichero, second: bloque
typedef vector<int> VI;
typedef vector<bool> VB;

vector<PII> disk;
vector<VI> fichero;
VI tam_acumulado;
VB mover;

int colocar_bien(int f, int b) {
    if (fichero[f][b] != tam_acumulado[f] + b) {
    	// Liberar primero la posición de destino
        if (disk[tam_acumulado[f] + b].first != 0) {
        	if (mover[tam_acumulado[f] + b]) {
        		// Buscar una posición vacía y llevar lo que haya en el destino de este bloque
        		int i = disk.size() - 1;
        		while (disk[i].first != 0) i--;
        		disk[i].first = disk[tam_acumulado[f] + b].first;
        		disk[i].second = disk[tam_acumulado[f] + b].second;
        		fichero[disk[tam_acumulado[f] + b].first][disk[tam_acumulado[f] + b].second] = i;
        		printf("%d %d\n", tam_acumulado[f] + b, i);
        	} else {
        		// Expandir recursivamente
        		mover[fichero[f][b]] = true;
        		colocar_bien(disk[tam_acumulado[f] + b].first, disk[tam_acumulado[f] + b].second);
        	}
        }
        // Quitar de la posicion vieja
        disk[fichero[f][b]].first = 0;
        disk[fichero[f][b]].second = 0;
        mover[fichero[f][b]] = false;
        printf("%d ", fichero[f][b]);
        // Mover a la nueva posicion
        disk[tam_acumulado[f] + b].first = f;
        disk[tam_acumulado[f] + b].second = b;
        fichero[f][b] = tam_acumulado[f] + b;
        printf("%d\n", fichero[f][b]);
        return 1;
    } else {
    	return 0;
    }
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m, n, k, cluster, opt, i, j;
	scanf("%d ", &m);
	while (m--) {
		scanf("%d %d ", &n, &k);
		disk = vector<PII>(n+1);
		fichero = vector<VI>(k+1, VI());
		VI tam(k+1);
		tam_acumulado = VI(k+1);

		tam[0] = tam_acumulado[0] = tam_acumulado[1] = 0;
		for (i = 1; i <= k; ++i) {
			scanf("%d ", &tam[i]);
			tam_acumulado[i] = tam_acumulado[i-1] + tam[i-1];
			fichero[i] = VI(tam[i] + 1);
			for (j = 1; j <= tam[i]; ++j) {
				scanf("%d ", &cluster);
				disk[cluster].first = i;
				disk[cluster].second = j;
				fichero[i][j] = cluster;
			}
		}

		opt = 0;
		mover = VB(n+1);
		for (i = 1; i <= k; ++i)
			for (j = 1; j <= tam[i]; ++j)
				opt += colocar_bien(i, j);

		if (opt == 0)
			puts("No optimization needed");

		if (m > 0)
			puts("");
	}

	return 0;
}
