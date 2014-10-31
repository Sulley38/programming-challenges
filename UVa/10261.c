#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SQR(a) ((a)*(a))
#define INF 10000000

int Space[501][10001];
int Side[501][10001];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, Length, Car[501], Result[501], N;
	int i, j, lastIn;
	scanf("%d ", &T);
	while (T--) {
		N = 1;
		scanf("%d %d ", &Length, &Car[1]);
		while (Car[N] > 0) {
			N++;
			scanf("%d ", &Car[N]);
		}
		Length *= 100;
		lastIn = 0;

		/* Space[i][j] = Mínimo espacio ocupado en el carril derecho habiendo metido i coches y con j ocupado en el izquierdo */
		/* Side[i][j] = Lado al que se envía el coche i-ésimo con j ocupado en el lado izquierdo. 0 = port, 1 = starboard */
		memset(Space[0], 0, sizeof Space[0]);
		for (i = 1; i < N; ++i) {
			for (j = 0; j <= Length; ++j) {
				if (j - Car[i] >= 0 && Space[i - 1][j - Car[i]] < INF) {
					if (Space[i - 1][j] + Car[i] <= Length) {
						/* Either side */
						Space[i][j] = MIN(Space[i - 1][j - Car[i]], Space[i - 1][j] + Car[i]);
						Side[i][j] = (Space[i - 1][j - Car[i]] < Space[i - 1][j] + Car[i]) ? 0 : 1;
						lastIn = i;
					} else {
						/* Left side */
						Space[i][j] = Space[i - 1][j - Car[i]];
						Side[i][j] = 0;
						lastIn = i;
					}
				} else if (Space[i - 1][j] + Car[i] <= Length) {
					/* Right side */
					Space[i][j] = Space[i - 1][j] + Car[i];
					Side[i][j] = 1;
					lastIn = i;
				} else {
					/* None of both */
					Space[i][j] = INF;
				}
			}
		}

		printf("%d\n", lastIn);
		j = Length;
		for (i = lastIn; i > 0; --i) {
			Result[i] = Side[i][j];
			if (Side[i][j] == 0)
				j -= Car[i];
		}
		for (i = 1; i <= lastIn; ++i)
			puts(Result[i] == 0 ? "port" : "starboard");
		if (T > 0) puts("");
	}


	return 0;
}
