#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int punt[43] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
			    24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,50,51,54,57,60};

int permutaciones(int a, int b, int c) {
	if (a == b) {
		return (a == c) ? 1 : 3;
	} else if (a == c || b == c) {
		return 3;
	} else {
		return 6;
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, i, j, k, comb, perm;
	scanf("%d ", &N);
	while (N > 0) {
		comb = perm = 0;
		/* Calcular combinaciones / permutaciones */
		for (i = 0; i < 43; ++i) {
			for (j = i; j < 43; ++j) {
				for (k = j; k < 43; ++k) {
					if (punt[i] + punt[j] + punt[k] == N) {
						comb++;
						perm += permutaciones(punt[i], punt[j], punt[k]);
					}
				}
			}
		}
		/* Imprimir resultado */
		if (comb > 0) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", N, comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, perm);
		} else {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
		}
		puts("**********************************************************************");
		scanf("%d ", &N);
	}
	puts("END OF OUTPUT");

	return 0;
}
