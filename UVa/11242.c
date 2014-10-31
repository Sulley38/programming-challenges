#include <stdio.h>
#include <stdlib.h>

int comp(const void * a, const void * b)
{
  if ( *(float*)a <  *(float*)b ) return -1;
  else if ( *(float*)a == *(float*)b ) return 0;
  else return 1;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int f, r, i, j;
	while (scanf("%d ", &f) > 0 && f > 0) {
		scanf("%d ", &r);
		float F[f], R[r];
		for (i = 0; i < f; ++i)
			scanf("%f ", &F[i]);
		for (i = 0; i < r; ++i)
			scanf("%f ", &R[i]);
		/* Calcular todos los dr */
		float D[f*r];
		for (i = 0; i < r; ++i)
			for (j = 0; j < f; ++j)
				D[i*f+j] = R[i] / F[j];
		qsort(D, f*r, sizeof(float), comp);
		/* Buscar maximo spread */
		float maxspread = D[1] / D[0], spread;
		for (i = 2; i < f*r; ++i) {
			spread = D[i] / D[i-1];
			if (spread > maxspread)
				maxspread = spread;
		}
		printf("%.2f\n", maxspread);
	}

	return 0;
}
