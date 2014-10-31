#include <stdio.h>
#include <string.h>

char digito[10][7] = {
		{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N'},
		{'N', 'Y', 'Y', 'N', 'N', 'N', 'N'},
		{'Y', 'Y', 'N', 'Y', 'Y', 'N', 'Y'},
		{'Y', 'Y', 'Y', 'Y', 'N', 'N', 'Y'},
		{'N', 'Y', 'Y', 'N', 'N', 'Y', 'Y'},
		{'Y', 'N', 'Y', 'Y', 'N', 'Y', 'Y'},
		{'Y', 'N', 'Y', 'Y', 'Y', 'Y', 'Y'},
		{'Y', 'Y', 'Y', 'N', 'N', 'N', 'N'},
		{'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
		{'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y'}
};

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i, j, k;
	while (scanf("%d ", &n) > 0 && n > 0) {
		char luces[10][9];
		int posible[10], posibles = 10-n+1;
		int roto[10][7];
		fgets(luces[0], 9, stdin);
		/* Comprobar qué número podría ser */
		memset(posible, 0, sizeof posible);
		for (i = n-1; i < 10; ++i) {
			posible[i] = 1;
			for (j = 0; j < 7 && posible[i]; ++j) {
				if (luces[0][j] == digito[i][j]) {
					roto[i][j] = 0;
				} else if (luces[0][j] == 'N' && digito[i][j] == 'Y') {
					roto[i][j] = 1;
				} else {
					posible[i] = 0;
					posibles--;
				}
			}
		}
		/* Probar si alguna de las opciones forma un countdown */
		for (i = 1; i < n; ++i) {
			fgets(luces[i], 9, stdin);
			for (j = n-i-1; j < 10-i && posibles > 0; ++j) {
				if (posible[j+1]) {
					/* Comprobar si es posible continuar el countdown, teniendo en cuenta los rotos */
					posible[j] = 1;
					for (k = 0; k < 7 && posible[j]; ++k) {
						if (luces[i][k] == 'Y' && (roto[j+1][k] || digito[j][k] == 'N')) {
							posible[j] = 0;
							posibles--;
						} else if (luces[i][k] == digito[j][k]) {
							roto[j][k] = roto[j+1][k];
						} else if (luces[i][k] == 'N' && digito[j][k] == 'Y') {
							roto[j][k] = 1;
						}
					}
				} else {
					posible[j] = 0;
				}
			}
		}
		if (posibles > 0)
			puts("MATCH");
		else
			puts("MISMATCH");
	}

	return 0;
}
