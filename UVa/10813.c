#include <stdio.h>

int bingo(int card[5][5]) {
	if ((card[0][0] == -1 && card[0][1] == -1 && card[0][2] == -1 && card[0][3] == -1 && card[0][4] == -1) ||
		(card[1][0] == -1 && card[1][1] == -1 && card[1][2] == -1 && card[1][3] == -1 && card[1][4] == -1) ||
		(card[2][0] == -1 && card[2][1] == -1 && card[2][2] == -1 && card[2][3] == -1 && card[2][4] == -1) ||
		(card[3][0] == -1 && card[3][1] == -1 && card[3][2] == -1 && card[3][3] == -1 && card[3][4] == -1) ||
		(card[4][0] == -1 && card[4][1] == -1 && card[4][2] == -1 && card[4][3] == -1 && card[4][4] == -1) ||
		(card[0][0] == -1 && card[1][0] == -1 && card[2][0] == -1 && card[3][0] == -1 && card[4][0] == -1) ||
		(card[0][1] == -1 && card[1][1] == -1 && card[2][1] == -1 && card[3][1] == -1 && card[4][1] == -1) ||
		(card[0][2] == -1 && card[1][2] == -1 && card[2][2] == -1 && card[3][2] == -1 && card[4][2] == -1) ||
		(card[0][3] == -1 && card[1][3] == -1 && card[2][3] == -1 && card[3][3] == -1 && card[4][3] == -1) ||
		(card[0][4] == -1 && card[1][4] == -1 && card[2][4] == -1 && card[3][4] == -1 && card[4][4] == -1) ||
		(card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) ||
		(card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1))
		return 1;
	else
		return 0;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, num, card[5][5], i, j, k;
	scanf("%d ", &n);
	while (n--) {
		scanf("%d %d %d %d %d ", &card[0][0], &card[0][1], &card[0][2], &card[0][3], &card[0][4]);
		scanf("%d %d %d %d %d ", &card[1][0], &card[1][1], &card[1][2], &card[1][3], &card[1][4]);
		scanf("%d %d %d %d ", &card[2][0], &card[2][1], &card[2][3], &card[2][4]);
		scanf("%d %d %d %d %d ", &card[3][0], &card[3][1], &card[3][2], &card[3][3], &card[3][4]);
		scanf("%d %d %d %d %d ", &card[4][0], &card[4][1], &card[4][2], &card[4][3], &card[4][4]);
		card[2][2] = -1;
		for (k = 1; k <= 75; k++) {
			scanf("%d ", &num);
			/* Marcar casilla */
			for (i = 0; i < 5; i++)
				for (j = 0; j < 5; j++)
					if (card[i][j] == num) {
						card[i][j] = -1;
						i = 5; j = 5;
					}
			/* Si se ha marcado un número, comprobar si hay bingo */
			if (i == 6 && bingo(card)) {
				printf("BINGO after %d numbers announced\n", k);
				while (k < 75)	{
					scanf("%d ", &num);
					k++;
				}
			}
		}
	}
	return 0;
}
