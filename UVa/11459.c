#include <stdio.h>
#include <string.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, b, c, i, desde, hasta, t, tirada, turno;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d %d ", &a, &b, &c);
		int posicionJugador[a], mover[100];
		memset(posicionJugador, 0, a * sizeof(int));
		memset(mover, -1, 100 * sizeof(int));

		/* Serpientes / escaleras */
		for (i = 0; i < b; ++i) {
			scanf("%d %d ", &desde, &hasta);
			mover[desde - 1] = hasta - 1;
		}

		/* Tiradas */
		turno = 0;
		for (i = 0; i < c; ++i) {
			scanf("%d ", &tirada);
			posicionJugador[turno] += tirada;
			if (posicionJugador[turno] > 99)
				posicionJugador[turno] = 99;
			else if (mover[posicionJugador[turno]] != -1)
				posicionJugador[turno] = mover[posicionJugador[turno]];

			if (posicionJugador[turno] == 99) {
				i++;
				/* Ignorar restantes */
				char buffer[16];
				while (i < c) {
					gets(buffer);
					i++;
				}
			}

			/* Siguiente jugador */
			turno++;
			if (turno == a)
				turno = 0;
		}

		/* Resultado */
		for (i = 0; i < a; ++i)
			printf("Position of player %d is %d.\n", i + 1, posicionJugador[i] + 1);
	}
	return 0;
}
