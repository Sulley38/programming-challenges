#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i, n;
	char carmichael[65000];

	/*srand(time(0));
	int a, j, test;
	// Criba de eratóstenes hasta 65000
	char es_primo[65000];
	for (i = 0; i < 65000; ++i)
		es_primo[i] = 1;
	for (i = 2; i < 65000; ++i)
		if (es_primo[i])
			for (j = 2; i*j < 65000; ++j)
				es_primo[i*j] = 0;

	// Precalcular números de Charmicael en el rango dado
	for (n = 2; n < 65000; ++n) {
		if (es_primo[n]) { // Es primo: normal
			carmichael[n] = 0;
		} else { // No es primo:
			for (i = 0; i < 10; ++i) {
				a = (rand() % (n-2)) + 2;
				test = 1;
				for (j = 0; j < n; ++j)
					test = (test * a) % n;
				if (test % n != a) { // Falla la prueba de Fermat: número normal
					carmichael[n] = 0;
					i = 12;
				}
			}
			if (i == 10) { // Cumple la prueba: número de Charmicael
				carmichael[n] = 1;
			}
		}
	}*/

	for (i = 0; i < 65000; ++i)
		carmichael[i] = 0;
	carmichael[561] = 1; carmichael[1105] = 1; carmichael[1729] = 1;
	carmichael[2465] = 1; carmichael[2821] = 1; carmichael[6601] = 1;
	carmichael[8911] = 1; carmichael[10585] = 1; carmichael[15841] = 1;
	carmichael[29341] = 1; carmichael[41041] = 1; carmichael[46657] = 1;
	carmichael[52633] = 1; carmichael[62745] = 1; carmichael[63973] = 1;

	scanf("%d", &n);
	while (n != 0) {
		if (carmichael[n] == 1)
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
		scanf("%d", &n);
	}

	return 0;
}

