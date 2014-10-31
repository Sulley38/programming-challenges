#include <stdio.h>

int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int bisiesto[201] = {0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0};

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i;
	while (scanf("%d", &n) > 0 && n != 0) {
		int d[n], m[n], y[n], c[n], numdias = 0, potencia = 0;
		scanf("%d %d %d %d", &d[0], &m[0], &y[0], &c[0]);

		for (i = 1; i < n; ++i) {
			scanf("%d %d %d %d", &d[i], &m[i], &y[i], &c[i]);
			/* Comprobar si hay datos del día anterior */
			if( (y[i] == y[i-1] && m[i] == m[i-1] && d[i] == d[i-1] + 1) /* Siguiente día */
			 || (y[i] == y[i-1] && m[i] == m[i-1] + 1 && d[i] == 1 && d[i-1] == ((bisiesto[y[i]-1900] && m[i-1] == 2) ? 29 : dias[m[i-1]-1])) /* Mes nuevo */
			 || (y[i] == y[i-1] + 1 && m[i] == 1 && m[i-1] == 12 && d[i] == 1 && d[i-1] == 31) /* Año nuevo */ ) {
				numdias++;
				potencia += c[i] - c[i-1];
			}
		}

		printf("%d %d\n", numdias, potencia);
	}

	return 0;
}
