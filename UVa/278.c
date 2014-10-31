#include <stdio.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m, n, t, x, y;
	char piece;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%c %d %d\n", &piece, &m, &n);
		if (piece == 'r' || piece == 'Q') { /* Torre o reina: el menor entre filas y columnas */
			printf("%d\n", (m < n) ? m : n);
		} else if (piece == 'k') { /* Caballo: una casilla sí, una no */
			x = m * n;
			printf("%d\n", (x % 2 == 0) ? (x / 2) : (x / 2) + 1);
		} else { /* Rey: fila sí, fila no; columna sí, columna no */
			x = (m % 2 == 0) ? (m / 2) : (m / 2 + 1);
			y = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
			printf("%d\n", x * y);
		}
	}
	return 0;
}
