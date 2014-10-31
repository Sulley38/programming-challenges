#include <stdio.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char valor[13], palo[13], letra_palo[4] = {'S', 'H', 'D', 'C'};
	int i, puntos_a, puntos_b, id_palo[13], cartas_palo[4], stopped[4], mascartas;
	while(scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c\n",
			&valor[0], &palo[0], &valor[1], &palo[1], &valor[2], &palo[2], &valor[3], &palo[3], &valor[4], &palo[4], &valor[5], &palo[5], &valor[6], &palo[6],
			&valor[7], &palo[7], &valor[8], &palo[8], &valor[9], &palo[9], &valor[10], &palo[10], &valor[11], &palo[11], &valor[12], &palo[12]) > 0) {
		puntos_a = puntos_b = cartas_palo[0] = cartas_palo[1] = cartas_palo[2] = cartas_palo[3] = stopped[0] = stopped[1] = stopped[2] = stopped[3] = 0;
		/* Cuenta palos */
		for (i = 0; i < 13; ++i) {
			if (palo[i] == 'S') {
				cartas_palo[0]++;
				id_palo[i] = 0;
			} else if (palo[i] == 'H') {
				cartas_palo[1]++;
				id_palo[i] = 1;
			} else if (palo[i] == 'D') {
				cartas_palo[2]++;
				id_palo[i] = 2;
			} else {
				cartas_palo[3]++;
				id_palo[i] = 3;
			}
		}
		/* Normas 5, 6, 7 */
		if (cartas_palo[0] == 2) puntos_a++;
		else if (cartas_palo[0] == 1 || cartas_palo[0] == 0) puntos_a += 2;
		if (cartas_palo[1] == 2) puntos_a++;
		else if (cartas_palo[1] == 1 || cartas_palo[1] == 0) puntos_a += 2;
		if (cartas_palo[2] == 2) puntos_a++;
		else if (cartas_palo[2] == 1 || cartas_palo[2] == 0) puntos_a += 2;
		if (cartas_palo[3] == 2) puntos_a++;
		else if (cartas_palo[3] == 1 || cartas_palo[3] == 0) puntos_a += 2;
		/* Suma puntos */
		for (i = 0; i < 13; ++i) {
			if (valor[i] == 'A') {
				puntos_a += 4;
				puntos_b += 4;
				stopped[id_palo[i]] = 1;
			} else if (valor[i] == 'K') {
				puntos_a += 3;
				puntos_b += 3;
				if (cartas_palo[id_palo[i]] == 1) {
					puntos_a--;
					puntos_b--;
				} else if (cartas_palo[id_palo[i]] > 1) {
					stopped[id_palo[i]] = 1;
				}
			} else if (valor[i] == 'Q') {
				puntos_a += 2;
				puntos_b += 2;
				if (cartas_palo[id_palo[i]] == 1 || cartas_palo[id_palo[i]] == 2) {
					puntos_a--;
					puntos_b--;
				} else if (cartas_palo[id_palo[i]] > 2) {
					stopped[id_palo[i]] = 1;
				}
			} else if (valor[i] == 'J') {
				puntos_a += 1;
				puntos_b += 1;
				if (cartas_palo[id_palo[i]] == 1 || cartas_palo[id_palo[i]] == 2 || cartas_palo[id_palo[i]] == 3) {
					puntos_a--;
					puntos_b--;
				}
			}
		}

		/* Seleccionar resultado */
		if (puntos_a < 14) {
			puts("PASS");
		} else if (puntos_b >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3]) {
			puts("BID NO-TRUMP");
		} else {
			mascartas = 0;
			if (cartas_palo[1] > cartas_palo[mascartas])
				mascartas = 1;
			if (cartas_palo[2] > cartas_palo[mascartas])
				mascartas = 2;
			if (cartas_palo[3] > cartas_palo[mascartas])
				mascartas = 3;
			printf("BID %c\n", letra_palo[mascartas]);
		}
	}

	return 0;
}
