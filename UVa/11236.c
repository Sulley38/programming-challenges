#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, b, c, d, sab, sabc;
	long long int pab, pabc;
	double prod, sum;
	for (a = 1; a <= 125; a++) {
		for (b = a; a + 3 * b <= 2000; b++) {
			pab = a * b;
			sab = a + b;
			for (c = b; sab + 2 * c <= 2000; c++) {
				pabc = pab * c;
				sabc = sab + c;
				if (pabc > 1000000) {
					d = (sabc * 1000000) / (pabc - 1000000);
					if (d >= c && sabc + d <= 2000) {
						prod = (pabc * d) / 100000000.0;
						sum = (sabc + d) / 100.0;
						if (fabs(prod - sum) < 1e-9)
							printf("%0.2f %0.2f %0.2f %0.2f\n", a / 100.0f, b / 100.0f, c / 100.0f, d / 100.0f);
					}
				}
			}
		}
	}

	return 0;
}
