#include <stdio.h>
/*#include <string.h>*/

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	/* Precalcular resultado */
	/*int k, m, noResuelto, i;
	for (k = 1; k < 14; ++k) {
		int buenos, malos;
		m = 1;
		noResuelto = 1;
		while (noResuelto) {*/
			/* Probar este m */
			/*buenos = malos = k;
			i = -1;
			while (malos > 0) {
				i = (i + m) % (buenos + malos);
				if (i >= buenos)
					malos--;
				else
					break;
				i--;
			}

			if (malos == 0 && buenos == k)
				noResuelto = 0;
			else
				m++;
		}
		printf("%d,", m);
	}*/

	int k, solucion[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
	while (scanf("%d ", &k) > 0 && k > 0)
		printf("%d\n", solucion[k]);

	return 0;
}
