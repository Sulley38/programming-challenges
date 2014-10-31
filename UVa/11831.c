#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char grid[100][102];
	int N, M, S;
	int x, y, dir; /* Dir: 0 = North, 1 = East, 2 = South, 3 = West */
	int MoveX[4] = {0, 1, 0, -1}, MoveY[4] = {-1, 0, 1, 0};
	int i, j, count;
	while (scanf("%d %d %d ", &N, &M, &S) && N > 0) {
		/* Read the grid */
		for (i = 0; i < N; ++i)
			fgets(grid[i], M + 2, stdin);
		/* Search the initial position */
		x = -1;
		for (i = 0; i < N && x < 0; ++i) {
			for (j = 0; j < M && x < 0; ++j) {
				if (grid[i][j] >= 'L' && grid[i][j] <= 'S') {
					x = j, y = i;
					switch (grid[i][j]) {
					case 'N':
						 dir = 0;
						 break;
					case 'S':
						dir = 2;
						break;
					case 'L':
						dir = 1;
						break;
					case 'O':
						dir = 3;
						break;
					}
					grid[i][j] = '.';
				}
			}
		}

		char instr[S + 1];
		/* Read and process the instruction */
		fgets(instr, S + 1, stdin);
		count = 0;
		for (i = 0; i < S; ++i) {
			if (instr[i] == 'D') {
				/* Right 90 deg */
				dir++;
				if (dir > 3) dir = 0;
			} else if (instr[i] == 'E') {
				/* Left 90 deg */
				dir--;
				if (dir < 0) dir = 3;
			} else {
				/* Move in the corresponding direction */
				if (y + MoveY[dir] >= 0 && y + MoveY[dir] < N && x + MoveX[dir] >= 0 && x + MoveX[dir] < M
						&& grid[y + MoveY[dir]][x + MoveX[dir]] != '#') {
					x += MoveX[dir], y += MoveY[dir];
					/* Take the sticker */
					if (grid[y][x] == '*') {
						count++;
						grid[y][x] = '.';
					}
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
