#include <stdio.h>

#define MAX_X 1000

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, X, i, j;
	int wind[10][MAX_X];
	unsigned int up, down, hold;
	unsigned int minfuel[10][MAX_X];
	scanf("%d ", &N);
	while (N--) {
		/* Leer datos de entrada */
		scanf("%d ", &X);
		X /= 100;
		for (i = 9; i >= 0; --i)
			for (j = 0; j < X; ++j)
				scanf("%d ", &wind[i][j]);
		/* Calcular matriz de costes mínimos */
		/* minfuel[i][j] = coste mínimo hasta la posición (i,j) */
		minfuel[0][0] = 0;
		for (j = 1; j < X; ++j) {
			for (i = 0; i < 10 && i < j && i <= X - j; ++i) {
				up = (i-1 >= 0) ? minfuel[i-1][j-1] + 60 - wind[i-1][j-1] : -1;
				down = (i+1 < 10 && i+1 <= j-1) ? minfuel[i+1][j-1] + 20 - wind[i+1][j-1] : -1;
				hold = minfuel[i][j-1] + 30 - wind[i][j-1];
				if (up < down) {
					minfuel[i][j] = (hold < up) ? hold : up;
				} else {
					minfuel[i][j] = (hold < down) ? hold : down;
				}
			}
			if (i < 10 && i == j)
				minfuel[i][j] = minfuel[i-1][j-1] + 60 - wind[i-1][j-1];
		}
		down = minfuel[1][X-1] + 20 - wind[1][X-1];
		hold = minfuel[0][X-1] + 30 - wind[0][X-1];
		printf("%d\n\n", down < hold ? down : hold);
	}


	return 0;
}
