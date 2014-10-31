#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, A, B, C, i, j, k;
	int y1, y2, z1, z2;
	long long int Cubo[20][20][20], CuboAcumZ[20][20][20], CuboAcumYZ[20][20][20], V;
	long long int maxsum, sum;
	scanf("%d ", &t);
	while (t--) {
		/* Leer la entrada */
		scanf("%d %d %d ", &A, &B, &C);
		for (i = 0; i < A; ++i)
			for (j = 0; j < B; ++j)
				for (k = 0; k < C; ++k)
					scanf("%Ld ", &Cubo[i][j][k]);
		maxsum = Cubo[0][0][0];
		/* Sumar el valor acumulado de la tercera dimensión */
		for (i = 0; i < A; ++i)
			for (j = 0; j < B; ++j) {
				CuboAcumZ[i][j][0] = Cubo[i][j][0];
				for (k = 1; k < C; ++k)
					CuboAcumZ[i][j][k] = Cubo[i][j][k] + CuboAcumZ[i][j][k-1];
			}
		/* Sumar el valor acumulado de la segunda dimensión a partir del acumulado de la tercera */
		for (i = 0; i < A; ++i)
			for (k = 0; k < C; ++k) {
				CuboAcumYZ[i][0][k] = CuboAcumZ[i][0][k];
				for (j = 1; j < B; ++j)
					CuboAcumYZ[i][j][k] = CuboAcumZ[i][j][k] + CuboAcumYZ[i][j-1][k];
			}
		/* Probar las posibilidades de reducir dos dimensiones */
		for (z1 = 0; z1 < C; z1++)
			for (z2 = z1; z2 < C; z2++)
				for (y1 = 0; y1 < B; y1++)
					for (y2 = y1; y2 < B; y2++) {
						sum = 0;
						for (i = 0; i < A; ++i) {
							V = CuboAcumYZ[i][y2][z2];
							if (y1 > 0) V -= CuboAcumYZ[i][y1 - 1][z2];
							if (z1 > 0) V -= CuboAcumYZ[i][y2][z1 - 1];
							if (y1 > 0 && z1 > 0) V += CuboAcumYZ[i][y1 - 1][z1 - 1];
							/* Kadane sobre la línea obtenida */
							sum += V;
							if (sum > maxsum)
								maxsum = sum;
							if (sum < 0)
								sum = 0;
						}
					}
		printf("%Ld\n", maxsum);
		if (t > 0) puts("");
	}

	return 0;
}
