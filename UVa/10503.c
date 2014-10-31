#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int d1, d2, p[15], q[15];
int Ep[16], Eq[16];

int poner_fichas(int ultima, int puestas) {
	if (ultima == n) {
		/* Comprobar si encaja con la última */
		if (Eq[ultima] == d1) return 1;
		else return 0;
	}
	int i;
	for (i = 0; i < m; ++i) {
		if (!(puestas & 1 << i)) {
			if (p[i] == Eq[ultima]) {
				/* Poner la ficha i-ésima en la posición ultima+1 tal cual */
				Ep[ultima + 1] = p[i], Eq[ultima + 1] = q[i];
				if (poner_fichas(ultima + 1, puestas | 1 << i)) return 1;
			}
			if (q[i] == Eq[ultima] && p[i] != q[i]) {
				/* Poner la ficha i-ésima en la posición ultima+1 girada */
				Ep[ultima + 1] = q[i], Eq[ultima + 1] = p[i];
				if (poner_fichas(ultima + 1, puestas | 1 << i)) return 1;
			}
		}
	}
	return 0;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i;
	while (scanf("%d %d ", &n, &m) && n > 0) {
		scanf("%d %d %d %d ", &Ep[0], &Eq[0], &d1, &d2);
		for (i = 0; i < m; ++i)
			scanf("%d %d ", &p[i], &q[i]);
		if (poner_fichas(0, 0))
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
