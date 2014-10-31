#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int SZ, P, X, Y, C, L, Avanzar;
	while (scanf("%d %d ", &SZ, &P) > 0 && (SZ != 0 || P != 0)) {
		X = SZ / 2 + 1, Y = SZ / 2 + 1, L = 1;
		/* Avanzar hasta el cuadrado impar más cercano (por exceso) */
		while (P > L*L)
			L += 2, X++, Y++;
		C = L * L;
		/* Retroceder las últimas cuatro rectas hasta dar con la casilla */
		if (P != C) {
			Avanzar = L - 1;
			while (P != C && Avanzar)
				X--, C--, Avanzar--;
			if (P != C) {
				Avanzar = L - 1;
				while (P != C && Avanzar)
					Y--, C--, Avanzar--;
				if (P != C) {
					Avanzar = L - 1;
					while (P != C && Avanzar)
						X++, C--, Avanzar--;
					if (P != C) {
						Avanzar = L - 2;
						while (P != C && Avanzar)
							Y++, C--, Avanzar--;
					}
				}
			}
		}

		printf("Line = %d, column = %d.\n", X, Y);
	}

	return 0;
}
