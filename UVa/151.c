#include <stdio.h>
/*#include <string.h>*/

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	/* Precalcular resultado */
	/*int m, n, noResuelto, i, avance;
	for (n = 13; n < 100; ++n) {
		int apagado[n], numApagados;
		m = 1;
		noResuelto = 1;
		while (noResuelto) {*/
			/* Probar este m */
			/*memset(apagado, 0, n * sizeof(int));
			apagado[0] = 1;
			numApagados = 1;
			i = 0;
			while (numApagados < n - 1) {
				avance = m;
				while (avance > 0) {
					i = (i + 1) % n;
					if (apagado[i] == 0)
						avance--;
				}
				apagado[i] = 1;
				numApagados++;
			}

			if (apagado[12] == 0)
				noResuelto = 0;
			else
				m++;
		}
		printf("%d,", m);
	}*/

	int n, soluciones[] = {1,18,10,11,7,17,11,15,29,5,21,13,26,14,11,23,22,9,73,17,42,7,98,15,61,22,84,24,30,9,38,15,54,27,9,61,38,22,19,178,38,53,79,68,166,20,9,22,7,21,72,133,41,10,82,92,64,129,86,73,67,19,66,115,52,24,22,176,10,57,137,239,41,70,60,116,81,79,55,102,49,5,22,54,52,113,15};
	while (scanf("%d ", &n) > 0 && n != 0)
		printf("%d\n", soluciones[n - 13]);

	return 0;
}
