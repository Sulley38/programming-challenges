#include <stdio.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m, woken_up, now_woken_up, processed, years, i, j;
	char w1, w2, w3;
	while (scanf(" %d ", &n) > 0) {
		scanf("%d ", &m);
		int connected[26], stimulus[26];
		memset(connected, 0, 26 * sizeof(int));
		memset(stimulus, 0, 26 * sizeof(int));
		woken_up = now_woken_up = processed = years = 0;
		/* Leer primeros despiertos */
		w1 = getchar(), w2 = getchar(), w3 = getchar();
		woken_up |= 1 << (w1 - 'A') | 1 << (w2 - 'A') | 1 << (w3 - 'A');
		w1 = getchar(); /* Salto de línea */
		while (m--) {
			w1 = getchar(), w2 = getchar(), w3 = getchar();
			/* Marcar conexiones */
			connected[w1 - 'A'] |= 1 << (w2 - 'A');
			connected[w2 - 'A'] |= 1 << (w1 - 'A');
		}

		while (woken_up != now_woken_up && __builtin_popcount(woken_up) != n) {
			now_woken_up = woken_up;
			/* Propagar estímulos */
			for (i = 0; i < 26; ++i) {
				if ((now_woken_up & (1 << i)) && !(processed & (1 << i))) {
					/* Procesar nodo: sumar cuenta a los adyacentes */
					for (j = 0; j < 26; ++j) {
						if ((connected[i] & (1 << j)) && !(now_woken_up & (1 << j))) {
							stimulus[j]++;
							if (stimulus[j] == 3)
								woken_up |= 1 << j;
						}
					}
					processed |= 1 << i;
				}
			}
			years++;
		}

		if (__builtin_popcount(woken_up) == n)
			printf("WAKE UP IN, %d, YEARS\n", years);
		else
			puts("THIS BRAIN NEVER WAKES UP");
	}

	return 0;
}
