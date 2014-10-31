#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Variables para el backtracking */
int n, impar;
int diagL, diagR;
int cuenta;

/*
 * Poner p alfiles en el trablero n*n, en sólo casillas blancas o sólo negras según corresponda.
 * La última posición en la que se ha puesto un alfil es (x,y).
 */
void poner_alfiles(int p, int x, int y) {
	while (y < n) {
		/* Avanzar a la siguiente casilla */
		x += 2;
		if (x == n) x = 1 - impar, y++;
		else if (x == n + 1) x = impar, y++;
		/* Intentar poner un alfil si no se amenaza con otro */
		if (y < n && !(diagL & 1 << (n+x-y)) && !(diagR & 1 << (x+y))) {
			if (p == 1) {
				/* Último alfil puesto: contabilizar combinación */
				cuenta++;
			} else {
				/* Poner otro más: llamada recursiva */
				diagL |= 1 << (n+x-y);
				diagR |= 1 << (x+y);
				poner_alfiles(p - 1, x, y);
				diagL &= ~(1 << (n+x-y));
				diagR &= ~(1 << (x+y));
			}
		}
	}
}

/*
 * Contar cuántas formas hay de colocar k alfiles en un tablero n*n, considerando
 * únicamente las casillas de color blanco si b = 1, negro en caso contrario.
 */

int comb[64][8][2]; /* Memorización */

int combinaciones(int k, int b) {
	/* Ningún alfil: 1 posibilidad */
	if (k == 0) return 1;
	/* Dar resultado precalculado */
	if (comb[k-1][n-1][b] != -1) return comb[k-1][n-1][b];
	/* Calcular por backtracking */
	diagL = diagR = cuenta = 0;
	poner_alfiles(k, b ? -1 : -2, 0);
	if (!impar) comb[k-1][n-1][1-b] = cuenta; /* Tablero de lado par: simétrico */
	return (comb[k-1][n-1][b] = cuenta);
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	memset(comb, -1, sizeof comb);
	int k, negros, blancos, i;
	long long int suma;
	while (scanf("%d %d ", &n, &k) && n > 0) {
		/* Construir el resultado */
		suma = 0;
		impar = n % 2;
		for (i = 0; i <= k; ++i) {
			/* Formas de poner i alfiles negros y k - i blancos */
			negros = combinaciones(i, 0);
			blancos = combinaciones(k-i, 1);
			suma += negros * blancos;
		}
		printf("%lld\n", suma);
	}

	return 0;
}
