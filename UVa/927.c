#include <stdio.h>

int c[21], deg;

/* Calcular a(n) a partir de los coeficientes c[i], para un n dado */
long long int a (const long long int n) {
	long long int sum = 0, powern = 1;
	int i;
	for (i = 0; i <= deg; ++i) {
		sum += c[i] * powern;
		powern *= n;
	}
	return sum;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int C, i;
	scanf("%d ", &C);
	while (C--) {
		int d, k;
		scanf("%d ", &deg);
		for (i = 0; i <= deg; ++i)
			scanf("%d ", &c[i]);
		scanf("%d %d ", &d, &k);
		/* Construir b(m) a partir de a(n), solo hasta el termino k-esimo */
		long long int n = 1, next_n = d, an = a(1);
		while (k--) {
			if (next_n == 0) {
				next_n = (++n) * d;
				an = a(n);
			}
			next_n--;
		}
		printf("%lld\n", an);
	}

	return 0;
}
