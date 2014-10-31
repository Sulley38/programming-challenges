#include <stdio.h>
#include <string.h>

/* Dimensiones del laberinto */
int b, w;

/* Si no hay pared a la derecha, girar.
 * Si la hay, avanzar.
 * Si no se puede, girar hacia el otro lado.
 */
void step (char m[b][w], int *x, int *y, int *d, int force) {
	if (*d == 0 && force == 1) {(*y)--;}
	else if (*d == 0 && (*x)+1 < w && m[*y][(*x)+1] == '0') {*d = 1; step(m, x, y, d, 1);}
	else if (*d == 0 && (*y)-1 >= 0 && m[(*y)-1][*x] == '0') {(*y)--;}
	else if (*d == 0) {*d = 3; step(m, x, y, d, 0);}
	else if (*d == 1 && force == 1) {(*x)++;}
	else if (*d == 1 && (*y)+1 < b && m[(*y)+1][*x] == '0') {*d = 2; step(m, x, y, d, 1);}
	else if (*d == 1 && (*x)+1 < w && m[*y][(*x)+1] == '0') {(*x)++;}
	else if (*d == 1) {*d = 0; step(m, x, y, d, 0);}
	else if (*d == 2 && force == 1) {(*y)++;}
	else if (*d == 2 && (*x)-1 >= 0 && m[*y][(*x)-1] == '0') {*d = 3; step(m, x, y, d, 1);}
	else if (*d == 2 && (*y)+1 < b && m[(*y)+1][*x] == '0') {(*y)++;}
	else if (*d == 2) {*d = 1; step(m, x, y, d, 0);}
	else if (*d == 3 && force == 1) {(*x)--;}
	else if (*d == 3 && (*y)-1 >= 0 && m[(*y)-1][*x] == '0') {*d = 0; step(m, x, y, d, 1);}
	else if (*d == 3 && (*x)-1 >= 0 && m[*y][(*x)-1] == '0') {(*x)--;}
	else if (*d == 3) {*d = 2; step(m, x, y, d, 0);}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i, j, x, y, dir, numvisitas[5];
	/* Direcciones: 0 N // 1 E // 2 S // 3 W */
	while (scanf("%d %d ", &b, &w) > 0 && (b != 0 || w != 0)) {
		int visitas[b][w];
		char maze[b][w];
		for (i = 0; i < b; ++i)
			for (j = 0; j < w; ++j)
				scanf("%c ", &maze[i][j]);
		memset(visitas, 0, sizeof visitas);

		/* Simular recorrido del robot */
		dir = 1;
		x = 0;
		y = b-1;
		visitas[y][x]++;
		step(maze, &x, &y, &dir, 0);
		while (x != 0 || y != b-1) {
			visitas[y][x]++;
			step(maze, &x, &y, &dir, 0);
		}

		/* Contar visitas */
		memset(numvisitas, 0, sizeof numvisitas);
		for (i = 0; i < b; ++i)
			for (j = 0; j < w; ++j)
				if (maze[i][j] == '0' && visitas[i][j] < 5)
					numvisitas[visitas[i][j]]++;

		printf("%3d%3d%3d%3d%3d\n", numvisitas[0], numvisitas[1], numvisitas[2], numvisitas[3], numvisitas[4]);
	}

	return 0;
}
