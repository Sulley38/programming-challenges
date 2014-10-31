#include <stdio.h>

int check0grados(const int N, const int n, char G[N][N], char P[n][n], const int X, const int Y) {
	if (X + n > N || Y + n > N) return 0;
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (G[Y+i][X+j] != P[i][j])
				return 0;
	return 1;
}

int check90grados(const int N, const int n, char G[N][N], char P[n][n], const int X, const int Y) {
	if (X - n + 1 < 0 || Y + n > N) return 0;
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (G[Y+j][X-i] != P[i][j])
				return 0;
	return 1;
}

int check180grados(const int N, const int n, char G[N][N], char P[n][n], const int X, const int Y) {
	if (X - n + 1 < 0 || Y - n + 1 < 0) return 0;
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (G[Y-i][X-j] != P[i][j])
				return 0;
	return 1;
}

int check270grados(const int N, const int n, char G[N][N], char P[n][n], const int X, const int Y) {
	if (X + n > N || Y - n + 1 < 0) return 0;
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (G[Y-j][X+i] != P[i][j])
				return 0;
	return 1;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, n, i, j, resp[4];
	while (scanf("%d %d ", &N, &n) > 0 && (N != 0 || n != 0)) {
		char grande[N][N], pequeno[n][n];
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; ++j)
				grande[i][j] = getchar();
			getchar();
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; ++j)
				pequeno[i][j] = getchar();
			getchar();
		}
		/* Calcular coincidencias */
		resp[0] = resp[1] = resp[2] = resp[3] = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; ++j)
				if (grande[i][j] == pequeno[0][0]) {
					resp[0] += check0grados(N, n, grande, pequeno, j, i);
					resp[1] += check90grados(N, n, grande, pequeno, j, i);
					resp[2] += check180grados(N, n, grande, pequeno, j, i);
					resp[3] += check270grados(N, n, grande, pequeno, j, i);
				}

		printf("%d %d %d %d\n", resp[0], resp[1], resp[2], resp[3]);
	}

	return 0;
}
