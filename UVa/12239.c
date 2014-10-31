#include <stdio.h>
#include <string.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, b, i, j;
	while (scanf("%d %d", &n, &b) > 0 && (n != 0 || b != 0)) {
		int bolas[b], posible[n+1];
		memset(posible, 0, (n + 1) * sizeof(int));
		for (i = 0; i < b; ++i)
			scanf("%d", &bolas[i]);

		int count = 0;
		for (i = 0; i < b; ++i)
			for (j = i + 1; j < b; ++j)
				if (bolas[i] - bolas[j] >= 0 ) {
					if (!posible[bolas[i] - bolas[j]]) {
						posible[bolas[i] - bolas[j]] = 1;
						count++;
					}
				} else if (!posible[bolas[j] - bolas[i]]) {
					posible[bolas[j] - bolas[i]] = 1;
					count++;
				}

		if (count == n) /* posible[0] siempre es verdadero */
			puts("Y");
		else
			puts("N");
	}

	return 0;
}
