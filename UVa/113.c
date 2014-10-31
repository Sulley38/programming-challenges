#include <math.h>
#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	double n, p;
	while (scanf("%lf %lf ", &n, &p) > 0)
		printf("%.0f\n", pow(p, 1 / n));

	return 0;
}
