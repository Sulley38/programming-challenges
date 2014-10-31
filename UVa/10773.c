#include <math.h>
#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, d, v, u, caso;
	scanf("%d ", &n);
	for (caso = 1; caso <= n; ++caso) {
		scanf("%d %d %d ", &d, &v, &u);
		if (u == 0 || u <= v) {
			printf("Case %d: can't determine\n", caso);
			continue;
		} else {
			double fastest = d / (double)u, shortest = d / sqrt(u*u - v*v);
			double diff = fabs(fastest - shortest);
			if (diff < 0.0005)
				printf("Case %d: can't determine\n", caso);
			else
				printf("Case %d: %.3f\n", caso, diff);
		}
	}

	return 0;
}
