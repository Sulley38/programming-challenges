#include <stdio.h>

int s, d;
long long int maxsum;

void maxsurplus(const int asignacion, const long long int suma5, const int ultimomes) {
	if (ultimomes == 12) { /* Todos los meses considerados */
		int i;
		long long suma = 0;
		for (i = 1; i <= 12; ++i) {
			if (asignacion & (1 << i))
				suma += s;
			else
				suma -= d;
		}
		if (suma > maxsum)
			maxsum = suma;
	} else {
		/* Superávit en el mes ultimomes+1 */
		if (ultimomes - 4 < 0) {
			maxsurplus(asignacion | (1 << (ultimomes + 1)), suma5 + s, ultimomes + 1);
		} else if (ultimomes == 4) {
			if (suma5 + s < 0)
				maxsurplus(asignacion | (1 << (ultimomes + 1)), suma5 + s, ultimomes + 1);
		} else {
			if ((asignacion & (1 << (ultimomes - 4))) && suma5 < 0)
				maxsurplus(asignacion | (1 << (ultimomes + 1)), suma5, ultimomes + 1);
			else if (suma5 + s + d < 0)
				maxsurplus(asignacion | (1 << (ultimomes + 1)), suma5 + s + d, ultimomes + 1);
		}
		/* Déficit en el mes ultimomes+1 */
		if (ultimomes - 4 < 0) {
			maxsurplus(asignacion, suma5 - d, ultimomes + 1);
		} else if (ultimomes == 4) {
			if (suma5 - d < 0)
				maxsurplus(asignacion, suma5 - d, ultimomes + 1);
		} else {
			if ((asignacion & (1 << (ultimomes - 4))) && suma5 - d - s < 0)
				maxsurplus(asignacion, suma5 - d - s, ultimomes + 1);
			else if (suma5 < 0)
				maxsurplus(asignacion, suma5, ultimomes + 1);
		}
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	while (scanf("%d %d ", &s, &d) > 0) {
		maxsum = -1;
		maxsurplus(0, 0, 0);
		if (maxsum < 0)
			puts("Deficit");
		else
			printf("%lld\n", maxsum);
	}

	return 0;
}
