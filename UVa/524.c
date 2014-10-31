#include <stdio.h>
#include <string.h>

char nums[16], puestos[17];
int n;
const unsigned int primos = 2693408940U; /* 10100000100010100010100010101100 */

#define es_primo(n) (primos & (1 << n))

/* Colocar un número en la posición 'posicion', habiéndose colocado hasta ahora 'puestos' */
void colocar(int posicion) {
	int i;
	if (posicion == n) { /* Todos puestos: imprimir solución */
		for (i = 0; i < n - 1; ++i)
			printf("%d ", nums[i]);
		printf("%d\n", nums[n-1]);
	} else { /* Expandir el ensayo: colocar un número que cumpla la condición */
		for (i = 2; i <= n; ++i) {
			if (!puestos[i] && es_primo((nums[posicion-1] + i)) && (posicion < n-1 || es_primo((i + 1)))) {
				puestos[i] = 1;
				nums[posicion] = i;
				colocar(posicion + 1);
				puestos[i] = 0;
			}
		}
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso = 1;
	nums[0] = 1;
	while (scanf("%d ", &n) > 0) {
		if (caso > 1) puts("");
		printf("Case %d:\n", caso++);
		memset(puestos, 0, sizeof puestos);
		colocar(1);
	}

	return 0;
}
