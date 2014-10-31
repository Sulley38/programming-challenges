#include <stdio.h>
#include <string.h>

/* Tipos de grupo: A -> 0, B -> 1, AB -> 2, O -> 3, Desc -> -1 */
/* Tipos de RH: + -> 0, - -> 1, Desc -> -1 */

/* Texto de cada tipo de sangre */
char texto_grupo[4][3] = {{'A',0,0}, {'B',0,0}, {'A','B',0}, {'O',0,0}};

/* Posibles soluciones para el padre: combinaciones[P][H], a lo sumo 4 posibilidades */
int combinaciones_padre[4][4][4] = {
		{{0,1,2,3}, {1,2,-1,-1}, {1,2,-1,-1}, {0,1,3,-1}}, /* Padre A */
		{{0,2,-1,-1}, {0,1,2,3}, {0,2,-1,-1}, {0,1,3,-1}}, /* Padre B */
		{{0,1,2,3}, {0,1,2,3}, {0,1,2,-1}, {-1,-1,-1,-1}}, /* Padre AB */
		{{0,2,-1,-1}, {1,2,-1,-1}, {-1,-1,-1,-1}, {0,1,3,-1}} /* Padre O */
};

/* Posibles soluciones para el hijo: combinaciones[P][P], a lo sumo 4 posibilidades */
int combinaciones_hijo[4][4][4] = {
		{{0,3,-1,-1}, {0,1,2,3}, {0,1,2,-1}, {0,3,-1,-1}}, /* Padre A */
		{{0,1,2,3}, {1,3,-1,-1}, {0,1,2,-1}, {1,3,-1,-1}}, /* Padre B */
		{{0,1,2,-1}, {0,1,2,-1}, {0,1,2,-1}, {0,1,-1,-1}}, /* Padre AB */
		{{0,3,-1,-1}, {1,3,-1,-1}, {0,1,-1,-1}, {3,-1,-1,-1}} /* Padre O */
};

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso = 0, resolver, i, ABO[3], RH[3], primera;
	char t[3][4];
	while (scanf("%s %s %s ", t[0], t[1], t[2]) > 0 && t[0][0] != 'E') {
		/* Determinar los tipos que se conocen */
		for (i = 0; i < 3; ++i) {
			if (!strcmp(t[i], "A+")) {
				ABO[i] = 0;
				RH[i] = 0;
			} else if (!strcmp(t[i], "B+")) {
				ABO[i] = 1;
				RH[i] = 0;
			} else if (!strcmp(t[i], "AB+")) {
				ABO[i] = 2;
				RH[i] = 0;
			} else if (!strcmp(t[i], "O+")) {
				ABO[i] = 3;
				RH[i] = 0;
			} else if (!strcmp(t[i], "A-")) {
				ABO[i] = 0;
				RH[i] = 1;
			} else if (!strcmp(t[i], "B-")) {
				ABO[i] = 1;
				RH[i] = 1;
			} else if (!strcmp(t[i], "AB-")) {
				ABO[i] = 2;
				RH[i] = 1;
			} else if (!strcmp(t[i], "O-")) {
				ABO[i] = 3;
				RH[i] = 1;
			} else {
				resolver = i;
				ABO[i] = -1;
				RH[i] = -1;
			}
		}

		primera = 1;
		if (resolver == 0) {
			/* Se desconoce el primer padre */
			printf("Case %d: ", ++caso);
			for (i = 0; i < 4 && combinaciones_padre[ABO[1]][ABO[2]][i] != -1; ++i) {
				if (primera) {
					printf("{%s+", texto_grupo[combinaciones_padre[ABO[1]][ABO[2]][i]]);
					primera = 0;
				} else {
					printf(", %s+", texto_grupo[combinaciones_padre[ABO[1]][ABO[2]][i]]);
				}
				if (RH[1] != 1 || RH[2] != 0)
					printf(", %s-", texto_grupo[combinaciones_padre[ABO[1]][ABO[2]][i]]);
			}
			if (primera)
				printf("IMPOSSIBLE %s %s\n", t[1], t[2]);
			else
				printf("} %s %s\n", t[1], t[2]);
		} else if (resolver == 1) {
			/* Se desconoce el segundo padre */
			printf("Case %d: %s ", ++caso, t[0]);
			for (i = 0; i < 4 && combinaciones_padre[ABO[0]][ABO[2]][i] != -1; ++i) {
				if (primera) {
					printf("{%s+", texto_grupo[combinaciones_padre[ABO[0]][ABO[2]][i]]);
					primera = 0;
				} else {
					printf(", %s+", texto_grupo[combinaciones_padre[ABO[0]][ABO[2]][i]]);
				}
				if (RH[0] != 1 || RH[2] != 0)
					printf(", %s-", texto_grupo[combinaciones_padre[ABO[0]][ABO[2]][i]]);
			}
			if (primera)
				printf("IMPOSSIBLE %s\n", t[2]);
			else
				printf("} %s\n", t[2]);
		} else {
			/* Se desconoce el hijo */
			printf("Case %d: %s %s ", ++caso, t[0], t[1]);
			if (ABO[0] == 3 && ABO[1] == 3 && RH[0] == 1 && RH[1] == 1) {
				/* Caso especial: única solución */
				printf("O-\n");
			} else {
				for (i = 0; i < 4 && combinaciones_hijo[ABO[0]][ABO[1]][i] != -1; ++i) {
					if (primera) {
						printf("{%s-", texto_grupo[combinaciones_hijo[ABO[0]][ABO[1]][i]]);
						primera = 0;
					} else {
						printf(", %s-", texto_grupo[combinaciones_hijo[ABO[0]][ABO[1]][i]]);
					}
					if (RH[0] == 0 || RH[1] == 0)
						printf(", %s+", texto_grupo[combinaciones_hijo[ABO[0]][ABO[1]][i]]);
				}
				printf("}\n");
			}
		}

	}

	return 0;
}
