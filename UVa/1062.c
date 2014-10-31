#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	char containers[10001], stack_top[10000];
	int caso = 0, stack_num, menor, diff, i, j;

	fgets(containers, 10000, stdin);
	while (containers[0] != 'e') {
		stack_num = i = 1;
		stack_top[0] = containers[0];
		while (containers[i] != '\n' && containers[i] != 0) {
			/* Intentar meterlo en la pila posible con menor diferencia */
			menor = -1;
			for (j = 0; j < stack_num; ++j) {
				diff = stack_top[j] - containers[i];
				if (diff >= 0 && (menor < 0 || diff < stack_top[menor] - containers[i]))
						menor = j;
			}

			/* Si no es posible, meterlo en una pila nueva */
			if (menor < 0)
				stack_top[stack_num++] = containers[i];
			else
				stack_top[menor] = containers[i];
			i++;
		}

		/* Resultado y leer siguiente caso */
		printf("Case %d: %d\n", ++caso, stack_num);
		fgets(containers, 10000, stdin);
	}

	return 0;
}
