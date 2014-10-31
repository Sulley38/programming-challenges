#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))
#define INF 10000000

const int opposite[6] = {1, 0, 3, 2, 5, 4}; /* cara opuesta a cada cara */
const char names[6][7] = { "front", "back", "left", "right", "top", "bottom" }; /* nombres de las caras*/
int color[501][6]; /* color[i][j] = color de la cara j del cubo i */
int longest[501][101]; /* longest[i][j] = longitud de la torre más alta con los cubos 1..i quedando el color j hacia abajo */
int faceup[501][101], colorup[501][101], cubeabove[501][101], cubeonbase[501][101];  /* cara superior/inferior/siguiente cubo/cubo en la base de la torre más alta con los cubos 1..i quedando el color j arriba */
int ans, cubetower[500], facetower[500];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, caso = 1;
	int upcolor, downcolor;
	int i, j, newj, k;
	scanf("%d ", &N);
	while (N > 0) {
		for (j = 0; j < 101; ++j) {
			longest[0][j] = 0;
			cubeonbase[0][j] = 0;
		}

		for (i = 1; i <= N; ++i) {
			for (j = 0; j < 101; ++j) {
				longest[i][j] = longest[i-1][j];
				faceup[i][j] = faceup[i-1][j];
				colorup[i][j] = colorup[i-1][j];
				cubeabove[i][j] = cubeabove[i-1][j];
				cubeonbase[i][j] = cubeonbase[i-1][j];
			}
			scanf("%d %d %d %d %d %d ", &color[i][0], &color[i][1], &color[i][2], &color[i][3], &color[i][4], &color[i][5]);
			for (j = 0; j < 6; ++j) {
				upcolor = color[i][j];
				downcolor = color[i][opposite[j]];
				if (longest[i-1][upcolor] + 1 > longest[i][downcolor]) {
					longest[i][downcolor] = longest[i-1][upcolor] + 1;
					faceup[i][downcolor] = j;
					colorup[i][downcolor] = upcolor;
					cubeabove[i][downcolor] = cubeonbase[i-1][upcolor];
					cubeonbase[i][downcolor] = i;
				}
			}
		}

		ans = 0;
		for (j = 1; j < 101; ++j)
			if (longest[N][j] > longest[N][ans])
				ans = j;
		j = N, k = ans;
		for (i = 0; i < longest[N][ans]; ++i) {
			cubetower[i] = cubeonbase[j][k];
			facetower[i] = faceup[j][k];
			newj = cubeabove[j][k];
			k = colorup[j][k];
			j = newj;
		}

		if (caso > 1) puts("");
		printf("Case #%d\n%d\n", caso++, longest[N][ans]);
		for (i = longest[N][ans] - 1; i >= 0; --i)
			printf("%d %s\n", cubetower[i], names[facetower[i]]);

		scanf("%d ", &N);
	}

	return 0;
}
