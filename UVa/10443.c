#include <stdio.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, r, c, n, i, j;
	scanf("%d ", &t);
	while (t--) {
		scanf("%d %d %d ", &r, &c, &n);
		/* Leer grid inicial */
		char grid[r][c], newgrid[r][c];
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				scanf("%c ", &grid[i][j]);
		memcpy(newgrid, grid, sizeof grid);
		/* Simular el paso del tiempo */
		while (n--) {
			for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
					if (grid[i][j] == 'R') {
						if ((i-1 >= 0 && grid[i-1][j] == 'P') || (i+1 < r && grid[i+1][j] == 'P')
						 || (j-1 >= 0 && grid[i][j-1] == 'P') || (j+1 < c && grid[i][j+1] == 'P'))
							newgrid[i][j] = 'P';
					} else if (grid[i][j] == 'S') {
						if ((i-1 >= 0 && grid[i-1][j] == 'R') || (i+1 < r && grid[i+1][j] == 'R')
						 || (j-1 >= 0 && grid[i][j-1] == 'R') || (j+1 < c && grid[i][j+1] == 'R'))
							newgrid[i][j] = 'R';
					} else {
						if ((i-1 >= 0 && grid[i-1][j] == 'S') || (i+1 < r && grid[i+1][j] == 'S')
						 || (j-1 >= 0 && grid[i][j-1] == 'S') || (j+1 < c && grid[i][j+1] == 'S'))
							newgrid[i][j] = 'S';
					}
			memcpy(grid, newgrid, sizeof newgrid);
		}
		/* Imprimir grid final */
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++)
				putchar(grid[i][j]);
			puts("");
		}
		if (t > 0)
			puts("");
	}
	return 0;
}
