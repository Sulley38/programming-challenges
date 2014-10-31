#include <stdio.h>

int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, d, m, n, y, count, leap;
	scanf("%d ", &n);
	for (a = 1; a <= n; a++) {
		scanf("%2d%2d%4d ", &m, &d, &y);
		count = 280;
		leap = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
		/* Contar 40 semanas */
		while (count > 0) {
			if (((!leap || m != 2) && count >= dias[m-1]) || (leap && m == 2 && count >= 29)) {
				/* Avanzar un mes */
				count -= dias[m-1];
				if (leap && m == 2)
					count--;
				m++;
				if (m == 13) {
					m = 1;
					y++;
					leap = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
				}
			} else {
				/* Avanzar día a día */
				while (count--) {
					d++;
					if (((!leap || m != 2) && d > dias[m-1]) || (leap && m == 2 && d > 29)) {
						d = 1;
						m++;
						if (m == 13) {
							m = 1;
							y++;
							leap = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0;
						}
					}
				}
			}
		}
		/* Output fecha y signo zodiacal correspondiente */
		printf("%d %02d/%02d/%04d ", a, m, d, y);
		switch (m) {
		case 1:
			if (d < 21) printf("capricorn\n");
			else printf("aquarius\n");
			break;
		case 2:
			if (d < 20) printf("aquarius\n");
			else printf("pisces\n");
			break;
		case 3:
			if (d < 21) printf("pisces\n");
			else printf("aries\n");
			break;
		case 4:
			if (d < 21) printf("aries\n");
			else printf("taurus\n");
			break;
		case 5:
			if (d < 22) printf("taurus\n");
			else printf("gemini\n");
			break;
		case 6:
			if (d < 22) printf("gemini\n");
			else printf("cancer\n");
			break;
		case 7:
			if (d < 23) printf("cancer\n");
			else printf("leo\n");
			break;
		case 8:
			if (d < 22) printf("leo\n");
			else printf("virgo\n");
			break;
		case 9:
			if (d < 24) printf("virgo\n");
			else printf("libra\n");
			break;
		case 10:
			if (d < 24) printf("libra\n");
			else printf("scorpio\n");
			break;
		case 11:
			if (d < 23) printf("scorpio\n");
			else printf("sagittarius\n");
			break;
		case 12:
			if (d < 23) printf("sagittarius\n");
			else printf("capricorn\n");
			break;
		}
	}

	return 0;
}
