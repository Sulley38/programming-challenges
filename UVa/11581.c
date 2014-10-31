#include <stdio.h>
#include <string.h>

void f(char src[3][3], char dst[3][3]) {
	dst[0][0] = (src[0][1] + src[1][0]) % 2;
	dst[0][1] = (src[0][0] + src[0][2] + src[1][1]) % 2;
	dst[0][2] = (src[0][1] + src[1][2]) % 2;
	dst[1][0] = (src[0][0] + src[1][1] + src[2][0]) % 2;
	dst[1][1] = (src[0][1] + src[1][0] + src[1][2] + src[2][1]) % 2;
	dst[1][2] = (src[0][2] + src[1][1] + src[2][2]) % 2;
	dst[2][0] = (src[1][0] + src[2][1]) % 2;
	dst[2][1] = (src[1][1] + src[2][0] + src[2][2]) % 2;
	dst[2][2] = (src[1][2] + src[2][1]) % 2;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, res, i, j;
	char c, g[3][3], g2[3][3];
	scanf("%d ", &n);
	while (n--) {
		/* Leer la cuadrícula */
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3; ++j) {
				scanf(" %c ", &c);
				g[i][j] = c - '0';
			}
		/* Aplicar f hasta que la cuadrícula no cambie */
		res = -1;
		f(g, g2);
		while (memcmp(g, g2, 9) != 0) {
			memcpy(g, g2, 9);
			f(g, g2);
			res++;
		}

		printf("%d\n", res);
	}

	return 0;
}
