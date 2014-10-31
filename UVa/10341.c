#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPS 1e-8

double newton(int p, int q, int r, int s, int t, int u) {
	double fx, fpx, x = 0.0, x1 = 0.5;
	while (fabs(x - x1) > EPS) {
		x = x1;
		fx = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
		fpx = -p * exp(-x) + q * cos(x) - r * sin(x) + s / (cos(x) * cos(x)) + 2 * t * x;
		x1 = x - fx / fpx;
	}
	return x1;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int p, q, r, s, t, u;
	double f0, f1;
	while (scanf("%d %d %d %d %d %d ", &p, &q, &r, &s, &t, &u) > 0) {
		f0 = p + r + u;
		f1 = p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u;
		if (fabs(f0) < EPS)
			puts("0.0000");
		else if (fabs(f1) < EPS)
			puts("1.0000");
		else if (f0 * f1 < EPS)
			printf("%.4lf\n", newton(p, q, r, s, t, u));
		else
			puts("No solution");
	}

	return 0;
}
