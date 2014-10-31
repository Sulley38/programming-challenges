#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int h, m;
	double ang_h, ang_m, min;
	while (scanf("%d:%d ", &h, &m) > 0 && (h != 0 || m != 0)) {
		ang_h = 30 * h + 0.5 * m;
		ang_m = 6 * m;

		/* Forma mínima de expresarlo */
		if (ang_h > ang_m) {
			min = ang_h - ang_m;
			if (min > 180)
				min = (360 - ang_h) + ang_m;
		} else {
			min = ang_m - ang_h;
			if (min > 180)
				min = (360 - ang_m) + ang_h;
		}

		printf("%.3f\n", min);
	}
	return 0;
}
