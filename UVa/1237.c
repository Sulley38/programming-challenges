#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 21

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, D, Q, P, i, match;
	char candidate[MAX_CHAR];
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &D);
		char M[D][MAX_CHAR];
		int H[D], L[D];
		for (i = 0; i < D; ++i)
			scanf("%s %d %d ", M[i], &L[i], &H[i]);
		scanf("%d ", &Q);
		while (Q--) {
			scanf("%d ", &P);
			/* Buscar posible resultado */
			match = 0;
			for (i = 0; i < D && match < 2; ++i) {
				if (L[i] <= P && H[i] >= P) {
					strcpy(candidate, M[i]);
					match++;
				}
			}
			if (match == 1)
				puts(candidate);
			else
				puts("UNDETERMINED");
		}
		if (T > 0)
			puts("");
	}

	return 0;
}
