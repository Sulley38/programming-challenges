#include <stdio.h>
#include <string.h>

static char linea[10001];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, k, cent, m, value[256], i;
	long amount;
	unsigned char ch;
	scanf("%d ", &n);
	while (n--) {
		/* Leer tabla de valores */
		scanf("%d ", &k);
		memset(value, 0, sizeof value);
		while (k--) {
			ch = getchar();
			scanf(" %d ", &cent);
			value[ch] = cent;
		}
		/* Leer líneas y sumar cantidad */
		amount = 0;
		scanf("%d ", &m);
		while (m--) {
			gets(linea);
			for (i = 0; linea[i] != 0; ++i)
				amount += value[(unsigned char)linea[i]];
		}

		printf("%ld.%02ld$\n", amount / 100, amount % 100);
	}

	return 0;
}
