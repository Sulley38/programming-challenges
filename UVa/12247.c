#include <stdio.h>
#include <string.h>

int usadas[52];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Devuelve cuál es la carta más baja, mayor que n, que no haya sido repartida */
int mayorQueSinUsar(const int n) {
	int i = n;
	while (usadas[i] == 1) i++;
	return i + 1;
}

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, b, c, x, y, z;
	while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y) > 0) {
		if (a == 0) break;
		/* Ascending order of a, b, c */
		if (b > a) swap(&a, &b);
		if (c > a) swap(&a, &c);
		if (c > b) swap(&b, &c);
		/* Ascending order of x, y */
		if (y > x) swap(&x, &y);

		/* Cartas repartidas */
		memset(usadas, 0, sizeof(int) * 52);
		usadas[a-1] = 1; usadas[b-1] = 1; usadas[c-1] = 1; usadas[x-1] = 1; usadas[y-1] = 1;

		/* Casos: */
		if (x > a) { /* Una gana fijo: x gana contra c */
			if (y > a) /* Tiene dos ganadas: entregar la menor carta posible */
				z = mayorQueSinUsar(0);
			else if (y > b) /* Entregar una más grande que b */
				z = mayorQueSinUsar(b);
			else /* Entregar una más grande que a */
				z = mayorQueSinUsar(a);
		} else if (x > b) { /* Pierde x contra a */
			if (y > b) /* Entregar una más grande que b */
				z = mayorQueSinUsar(b);
			else /* Pierde y contra b: no puede ganar */
				z = -1;
		} else {
			z = -1;
		}

		if (z > 52) /* No hay suficientes cartas */
			z = -1;

		printf("%d\n", z);
	}

	return 0;
}
