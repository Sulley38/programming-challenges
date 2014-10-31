#include <stdio.h>

#define ABS(n) (n < 0 ? -n : n)

int numdigitos(int n) {
	int d = 0;
	while (n > 0) {
		n /= 10;
		d++;
	}
	return d;
}

int gcd(int a, int b) {
	if (a < b)
		return gcd(b, a);
	int c;
	while (b != 0) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso = 0, n, suma, i, j, A, B, C, NA, NC, GCD;
	while (scanf("%d ", &n) > 0 && n != 0) {
		suma = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d ", &j);
			suma += j;
		}

		printf("Case %d:\n", ++caso);
		A = suma / n;
		B = suma - A * n;
		C = n;
		if (B == 0) {
			/* Entero */
			if (A < 0)
				printf("- ");
			printf("%d\n", ABS(A));
		} else {
			/* Fracción */
			GCD = gcd(ABS(B), ABS(C));
			B /= GCD, C /= GCD;
			NA = numdigitos(ABS(A)), NC = numdigitos(ABS(C));
			if (A != 0) {
				/* Número mixto */
				if (A < 0)
					printf("  ");
				printf("%*d\n", NA + NC, ABS(B));
				if (A < 0)
					printf("- ");
				printf("%d", ABS(A));
				for (i = 0; i < NC; ++i)
					putchar('-');
				putchar('\n');
				if (A < 0)
					printf("  ");
				printf("%*d\n", NA + NC, C);
			} else {
				/* Pura */
				if (B < 0)
					printf("  ");
				printf("%*d\n", NC, ABS(B));
				if (B < 0)
					printf("- ");
				for (i = 0; i < NC; ++i)
					putchar('-');
				putchar('\n');
				if (B < 0)
					printf("  ");
				printf("%*d\n", NC, C);
			}
		}
	}

	return 0;
}
