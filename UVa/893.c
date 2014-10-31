#include <stdio.h>

int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, d, m, y, bisiesto, bisiesto_sig;
	while (scanf("%d %d %d %d ", &n, &d, &m, &y) > 0 && d > 0) {
		while (n > 0) {
			bisiesto = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
			bisiesto_sig = (((y+1) % 4 == 0 && (y+1) % 100 != 0) || (y+1) % 400 == 0) ? 1 : 0;
			if (m < 3 && ((!bisiesto && n >= 365) || (n >= 366 && bisiesto))) {
				/* Avanzar año a año */
				n -= bisiesto ? 366 : 365;
				y++;
			} else if (m >= 3 && ((!bisiesto_sig && n >= 365) || (n >= 366 && bisiesto_sig))) {
				/* Avanzar año a año */
				n -= bisiesto_sig ? 366 : 365;
				y++;
			} else if (((!bisiesto || m != 2) && n >= dias[m-1]) || (bisiesto && m == 2 && n >= 29)) {
				/* Avanzar mes a mes */
				n -= dias[m-1];
				if (bisiesto && m == 2)
					n--;
				m++;
				if (m == 13) {
					m = 1;
					y++;
				}
			} else {
				/* Avanzar día a día */
				while (n--) {
					d++;
					if (((!bisiesto || m != 2) && d > dias[m-1]) || (bisiesto && m == 2 && d > 29)) {
						d = 1;
						m++;
						if (m == 13) {
							m = 1;
							y++;
						}
					}
				}
			}
		}

		printf("%d %d %d\n", d, m, y);
	}

	return 0;
}
