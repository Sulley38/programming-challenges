#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, sheets, p1, p2, i, front;
	while (scanf("%d ", &n) > 0 && n > 0) {
		printf("Printing order for %d pages:\n", n);
		sheets = n / 4;
		if (n % 4 != 0) sheets++;
		/* Simular secuencia */
		i = 1; front = 1;
		for (p1 = 1, p2 = sheets * 4; p1 < p2; ++p1, --p2) {
			if (p2 > n && p1 <= n) {
				if (front)
					printf("Sheet %d, front: Blank, %d\n", i, p1);
				else
					printf("Sheet %d, back : %d, Blank\n", i, p1);
			} else if (p2 <= n && p1 <= n) {
				if (front)
					printf("Sheet %d, front: %d, %d\n", i, p2, p1);
				else
					printf("Sheet %d, back : %d, %d\n", i, p1, p2);
			}
			/* Cambiar de página */
			if (front) {
				front = 0;
			} else {
				i++;
				front = 1;
			}
		}
	}

	return 0;
}
