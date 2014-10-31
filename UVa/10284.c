#include <stdio.h>
#include <string.h>

void marcar(int t[8][8], const int x, const int y, char pieza[8][8]) {
	int i;
	t[y][x] = 0;
	switch (pieza[y][x]) {
	case 'p': /* Peón negro */
		if (y + 1 < 8) {
			if (x - 1 >= 0)
				t[y+1][x-1] = 0;
			if (x + 1 < 8)
				t[y+1][x+1] = 0;
		}
		break;
	case 'P': /* Peón blanco */
		if (y - 1 >= 0) {
			if (x - 1 >= 0)
				t[y-1][x-1] = 0;
			if (x + 1 < 8)
				t[y-1][x+1] = 0;
		}
		break;
	case 'N': /* Caballos */
	case 'n':
		if (y - 2 >= 0) {
			if (x - 1 >= 0)
				t[y-2][x-1] = 0;
			if (x + 1 < 8)
				t[y-2][x+1] = 0;
		}
		if (y - 1 >= 0) {
			if (x - 2 >= 0)
				t[y-1][x-2] = 0;
			if (x + 2 < 8)
				t[y-1][x+2] = 0;
		}
		if (y +  1 < 8) {
			if (x - 2 >= 0)
				t[y+1][x-2] = 0;
			if (x + 2 < 8)
				t[y+1][x+2] = 0;
		}
		if (y +  2 < 8) {
			if (x - 1 >= 0)
				t[y+2][x-1] = 0;
			if (x + 1 < 8)
				t[y+2][x+1] = 0;
		}
		break;
	case 'B': /* Alfiles */
	case 'b':
		for (i = 1; y-i >= 0 && x-i >= 0 && !pieza[y-i][x-i]; i++)
			t[y-i][x-i] = 0;
		for (i = 1; y-i >= 0 && x+i < 8 && !pieza[y-i][x+i]; i++)
			t[y-i][x+i] = 0;
		for (i = 1; y+i < 8 && x-i >= 0 && !pieza[y+i][x-i]; i++)
			t[y+i][x-i] = 0;
		for (i = 1; y+i < 8 && x+i < 8 && !pieza[y+i][x+i]; i++)
			t[y+i][x+i] = 0;
		break;
	case 'R': /* Torres */
	case 'r':
		for (i = 1; y-i >= 0 && !pieza[y-i][x]; i++)
			t[y-i][x] = 0;
		for (i = 1; x-i >= 0 && !pieza[y][x-i]; i++)
			t[y][x-i] = 0;
		for (i = 1; x+i < 8 && !pieza[y][x+i]; i++)
			t[y][x+i] = 0;
		for (i = 1; y+i < 8 && !pieza[y+i][x]; i++)
			t[y+i][x] = 0;
		break;
	case 'Q': /* Reina */
	case 'q':
		for (i = 1; y-i >= 0 && x-i >= 0 && !pieza[y-i][x-i]; i++)
			t[y-i][x-i] = 0;
		for (i = 1; y-i >= 0 && x+i < 8 && !pieza[y-i][x+i]; i++)
			t[y-i][x+i] = 0;
		for (i = 1; y+i < 8 && x-i >= 0 && !pieza[y+i][x-i]; i++)
			t[y+i][x-i] = 0;
		for (i = 1; y+i < 8 && x+i < 8 && !pieza[y+i][x+i]; i++)
			t[y+i][x+i] = 0;
		for (i = 1; y-i >= 0 && !pieza[y-i][x]; i++)
			t[y-i][x] = 0;
		for (i = 1; x-i >= 0 && !pieza[y][x-i]; i++)
			t[y][x-i] = 0;
		for (i = 1; x+i < 8 && !pieza[y][x+i]; i++)
			t[y][x+i] = 0;
		for (i = 1; y+i < 8 && !pieza[y+i][x]; i++)
			t[y+i][x] = 0;
		break;
	case 'K': /* Rey */
	case 'k':
		if (y - 1 >= 0 && x - 1 >= 0)
			t[y-1][x-1] = 0;
		if (y - 1 >= 0)
			t[y-1][x] = 0;
		if (y - 1 >= 0 && x + 1 < 8)
			t[y-1][x+1] = 0;
		if (x - 1 >= 0)
			t[y][x-1] = 0;
		if (x + 1 < 8)
			t[y][x+1] = 0;
		if (y + 1 < 8 && x - 1 >= 0)
			t[y+1][x-1] = 0;
		if (y + 1 < 8)
			t[y+1][x] = 0;
		if (y + 1 < 8 && x + 1 < 8)
			t[y+1][x+1] = 0;
		break;
	}
}

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char fen[256];
	while (gets(fen)) {
		char tablero[8][8];
		memset(tablero, 0, 64 * sizeof(char));
		/* Formar el tablero */
		int i = 0, j = 0, l;
		for (l = 0; fen[l] != '\0'; ++l) {
			if (fen[l] >= '1' && fen[l] <= '9') {
				j += fen[l] - '0';
			} else if (fen[l] == '/') {
				i++;
				j = 0;
			} else {
				tablero[i][j] = fen[l];
				j++;
			}

		}
		/* Marcar las casillas ocupadas o amenzadas */
		int libre[8][8];
		memset(libre, 1, 64 * sizeof(int));
		for (i = 0; i < 8; ++i)
			for (j = 0; j < 8; ++j)
				if (tablero[i][j])
					marcar(libre, j, i, tablero);
		/* Contar el resultado */
		int cuenta = 0;
		for (i = 0; i < 8; ++i)
			for (j = 0; j < 8; ++j)
				if (libre[i][j])
					cuenta++;
		printf("%d\n", cuenta);
	}

	return 0;
}
