#include <math.h>
#include <stdio.h>

void calcularFactores(double* A, double* B, double* CX, double* CY, int* N) {
	double suma_xy = 0, suma_xx = 0, suma_x = 0, suma_y = 0;
	int i;
	for (i = 0; i < *N; ++i) {
		suma_xy += CX[i]*CY[i];
		suma_xx += CX[i]*CX[i];
		suma_x += CX[i];
		suma_y += CY[i];
	}
	*A = ((*N * suma_xy) - (suma_x * suma_y)) / ((*N * suma_xx) - (suma_x * suma_x));
	*B = (suma_y - (*A * suma_x)) / *N;
}

int main() {
/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	int N, P, i;
	scanf("%d", &N);
	while (N > 1) {
		double cX[N], cY[N], X;
		for (i = 0; i < N; ++i)
			scanf("%lf %lf", &cX[i], &cY[i]);

		double a, b;
		calcularFactores(&a, &b, cX, cY, &N);

		if (isnan(a) || isnan(b)) {
			puts("IMPOSSIBLE");
			scanf("%d", &P);
			for (i = 0; i < P; ++i)
				scanf("%lf", &X);
		} else {
			scanf("%d", &P);
			for (i = 0; i < P; ++i) {
				scanf("%lf", &X);
				printf("%.3lf\n", a*X + b);
			}
		}

		scanf("%d", &N);
		if (N > 1)
			puts("");
	}

	return 0;
}

