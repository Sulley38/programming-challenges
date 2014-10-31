#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
	return ( *(char*)a - *(char*)b );
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, K, a, b, c, d, e, matches, found;
	char C1[6][6], C2[6][6], orden[6];
	int longC1[5], repeated[5];

	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &K);
		scanf(" %s %s %s %s %s %s ", C1[0], C1[1], C1[2], C1[3], C1[4], C1[5]);
		scanf(" %s %s %s %s %s %s ", C2[0], C2[1], C2[2], C2[3], C2[4], C2[5]);
		/* Preprocesar el primer cuadrado: quedarse sólo con las letras válidas */
		for (a = 0; a < 5; ++a) {
			longC1[a] = 6;
			repeated[a] = 0;
			for (b = 0; b < longC1[a]; ++b) {
				/* Buscar C1[b][a] en C2[X][a] */
				found = 0;
				for (c = 0; c < 6; ++c)
					if (C1[b][a] == C2[c][a])
						found = 1;
				if (!found || (repeated[a] & 1 << (C1[b][a] - 'A'))) {
					longC1[a]--;
					for (c = b; c < longC1[a]; ++c)
						C1[c][a] = C1[c+1][a];
					b--;
				} else {
					repeated[a] |= 1 << (C1[b][a] - 'A');
				}
			}
		}
		/* Ordenar alfabéticamente las columnas para hacer la búsqueda en orden */
		for (a = 0; a < 5; ++a) {
			for (b = 0; b < longC1[a]; ++b)
				orden[b] = C1[b][a];
			qsort(orden, longC1[a], sizeof (char), cmp);
			for (b = 0; b < longC1[a]; ++b)
				C1[b][a] = orden[b];
		}
		/* Buscar todas las contraseñas posibles */
		matches = 0;
		for (a = 0; a < longC1[0] && matches < K; ++a)
			for (b = 0; b < longC1[1] && matches < K; ++b)
				for (c = 0; c < longC1[2] && matches < K; ++c)
					for (d = 0; d < longC1[3] && matches < K; ++d)
						for (e = 0; e < longC1[4] && matches < K; ++e)
							matches++;
		/* Imprimir el resultado */
		if (matches == K) {
			printf("%c%c%c%c%c\n", C1[a-1][0], C1[b-1][1], C1[c-1][2], C1[d-1][3], C1[e-1][4]);
		} else {
			puts("NO");
		}
	}

	return 0;
}
