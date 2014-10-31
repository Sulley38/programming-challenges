#include <stdio.h>

int n, t, nums[12], elem_suma[12], num_elem, suma, alguno;

void hacer_suma(int ultimo) {
	int i, j;
	for (i = ultimo + 1; i < n; ++i) {
		/* Saltar números repetidos para no repetir una suma */
		if (i > ultimo + 1 && nums[i] == nums[i-1]) continue;
		/* Intentar añadir un elemento a la suma */
		suma += nums[i];
		if (suma == t) { /* Suma completada: imprimir */
			for (j = 0; j < num_elem; j++)
				printf("%d+", elem_suma[j]);
			printf("%d\n", nums[i]);
			alguno = 1;
		} else if (suma < t) { /* Expandir la búsqueda */
			elem_suma[num_elem] = nums[i];
			num_elem++;
			hacer_suma(i);
			num_elem--;
		}
		suma -= nums[i];
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i;
	while (scanf("%d %d ", &t, &n) > 0 && n > 0) {
		for (i = 0; i < n; ++i)
			scanf("%d ", &nums[i]);
		printf("Sums of %d:\n", t);
		num_elem = suma = alguno = 0;
		hacer_suma(-1);
		if (!alguno)
			puts("NONE");
	}
	return 0;
}
