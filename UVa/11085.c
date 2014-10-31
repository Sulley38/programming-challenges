#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solucion;
int S[92][8];
int fila[8];

void calcular_soluciones(int ultima) {
	int i, j, valido;
	for (i = 0; i < 8; ++i) {
		/* Intentar poner una reina en la fila i */
		fila[ultima+1] = i;
		/* Comprobar si no se amenaza con otra */
		valido = 1;
		for (j = 0; j <= ultima && valido; ++j)
			if (fila[j] == i || j + fila[j] == ultima + 1 + i || j - fila[j] == ultima + 1 - i)
				valido = 0;
		/* Poner una reina más o guardar la solución */
		if (valido) {
			if (ultima == 6)
				memcpy(S[solucion++], fila, sizeof fila);
			else
				calcular_soluciones(ultima + 1);
		}
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solucion = 0;
	calcular_soluciones(-1);
	int R[8], minpasos, pasos, caso = 0, i, j;
	while (scanf("%d %d %d %d %d %d %d %d ", &R[0], &R[1], &R[2], &R[3], &R[4], &R[5], &R[6], &R[7]) > 0) {
		/* Buscar la solución en menos pasos */
		minpasos = 8;
		for (i = 0; i < 92; ++i) {
			pasos = 0;
			for (j = 0; j < 8; ++j)
				if (S[i][j] + 1 != R[j])
					pasos++;
			if (pasos < minpasos)
				minpasos = pasos;
		}
		printf("Case %d: %d\n", ++caso, minpasos);
	}

	return 0;
}
