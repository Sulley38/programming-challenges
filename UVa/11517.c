#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12000

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, p, n, i, j;
	int V[100];
	/* MinCoins[i] = nº mínimo de monedas necesarias para lograr la cantidad i */
	unsigned int MinCoins[MAX+1];

	scanf("%d ", &t);
	while (t--) {
		memset(MinCoins, -1, sizeof MinCoins);
		MinCoins[0] = 0;

		scanf("%d %d ", &p, &n);
		for (i = 0; i < n; ++i) {
			scanf("%d ", &V[i]);
			for (j = MAX; j >= V[i]; --j)
				if (MinCoins[j - V[i]] < -1U && MinCoins[j - V[i]] + 1 < MinCoins[j])
					MinCoins[j] = MinCoins[j - V[i]] + 1;
		}

		while (MinCoins[p] == -1U) p++;
		printf("%d %d\n", p, MinCoins[p]);
	}

	return 0;
}
