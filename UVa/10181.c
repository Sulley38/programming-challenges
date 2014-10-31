#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int puzzle[4][4], distancia;
int huecoX, huecoY;
int limiteProf;
char solucion[51];

/* Posición de cada pieza en el puzzle final (coordenadas X e Y) */
int finalX[16] = {3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
int finalY[16] = {3, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};

/* Direcciones para expandir la búsqueda */
int dirX[4] = {0, -1, 1, 0}, dirY[4] = {-1, 0, 0, 1};
char mov[4] = {'U', 'L', 'R', 'D'}, mov_prohibido[4] = {'D', 'R', 'L', 'U'};

/* Heurístico: distancia Manhattan de cada ficha a su posición en el puzzle final */
int heuristico() {
	int suma = 0, i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (puzzle[i][j] != 0)
				suma += abs(finalX[puzzle[i][j]] - j) + abs(finalY[puzzle[i][j]] - i);
	return suma;
}

/* Comprueba si el puzzle tiene solución (contando inversiones)
   http://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html */
int tiene_solucion() {
	int inversiones = 0, i, j, k, l;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			if (puzzle[i][j] > 1) {
				for (k = i; k < 4; ++k)
					for (l = (k == i) ? j + 1 : 0; l < 4; ++l)
						if (puzzle[k][l] > 0 && puzzle[i][j] > puzzle[k][l])
							inversiones++;
			}
		}
	}
	return 1 - ((inversiones + huecoY + 1) % 2);
}

/* Exploración del espacio de estados, IDA*
   Devuelve -1 si ha encontrado una solución */
int buscar(const int pasos, int previsto, const char ultimo_mov) {
	int resultado, minresultado = 10000000, nuevo_previsto, X, Y, i;
	/* Expandir la búsqueda en profundidad: 4 posibles direcciones */
	for (i = 0; i < 4; ++i) {
		X = huecoX + dirX[i], Y = huecoY + dirY[i];
		if (X >= 0 && X <= 3 && Y >= 0 && Y <= 3 && ultimo_mov != mov_prohibido[i]) {
			/* Hacer el cambio */
			nuevo_previsto = previsto - abs(finalX[puzzle[Y][X]] - X) - abs(finalY[puzzle[Y][X]] - Y);
			puzzle[huecoY][huecoX] = puzzle[Y][X];
			puzzle[Y][X] = 0;
			nuevo_previsto += abs(finalX[puzzle[huecoY][huecoX]] - huecoX) + abs(finalY[puzzle[huecoY][huecoX]] - huecoY);
			huecoY = Y, huecoX = X;
			solucion[pasos] = mov[i];
			/* Llamada recursiva */
			if (nuevo_previsto == 0) {
				solucion[pasos+1] = 0;
				return -1;
			} else if (pasos + 1 + nuevo_previsto <= limiteProf) {
				resultado = buscar(pasos+1, nuevo_previsto, mov[i]);
				if (resultado < 0) return resultado;
			} else if (pasos + 1 + nuevo_previsto < minresultado) {
				minresultado = pasos + 1 + nuevo_previsto;
			}
			/* Deshacer el cambio */
			huecoY -= dirY[i], huecoX -= dirX[i];
			puzzle[Y][X] = puzzle[huecoY][huecoX];
			puzzle[huecoY][huecoX] = 0;
		}
	}
	return minresultado;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, i, j;
	scanf("%d ", &N);
	while (N--) {
		/* Leer datos de entrada */
		for (i = 0; i < 4; ++i) {
			for (j = 0; j < 4; ++j) {
				scanf("%d ", &puzzle[i][j]);
				if (puzzle[i][j] == 0) {
					huecoX = j, huecoY = i;
				}
			}
		}
		/* Comprobar si el puzzle tiene solución */
		if (tiene_solucion()) {
			/* Lanzar la búsqueda. Aumentar el límite de profundidad en caso de no éxito */
			distancia = limiteProf = heuristico();
			while ((limiteProf = buscar(0, distancia, 0)) > 0) {
				if (limiteProf > 50)
					limiteProf = 50;
			}
			/* Imprimir solución */
			puts(solucion);
		} else {
			puts("This puzzle is not solvable.");
		}
	}

	return 0;
}
