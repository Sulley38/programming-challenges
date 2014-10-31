#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300000

int array[MAX], tail[MAX], parent[MAX];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d ", &array[0]);
	tail[0] = 0;
	parent[0] = -1;
	int a = 1, maxlength = 1, i, l, r;
	while (scanf("%d ", &array[a]) > 0) {
		if (array[a] < array[tail[0]]) {
			/* Nueva lista de longitud 1 */
			tail[0] = a;
		} else if (array[a] > array[tail[maxlength - 1]]) {
			/* Nueva lista de longitud máxima */
			parent[a] = tail[maxlength - 1];
			tail[maxlength++] = a;
		} else {
			/* Actualizar el último elemento de una lista de longitud intermedia */
			/* Se busca la lista que termine en el número más alto posible sin llegar a ser array[a] */
			i = l = 0, r = maxlength - 1;
			while (r - l > 0) {
				i = (r + l) / 2;
				if (array[tail[i + 1]] >= array[a]) {
					r = i;
					if (array[tail[i]] >= array[a])
						r = i - 1;
					else
						l = i;
				} else {
					l = i + 1;
				}
			}
			parent[a] = tail[l];
			tail[l + 1] = a;
		}
		a++;
	}
	/* Construir la secuencia resultante invertida */
	int inverse[maxlength], j = tail[maxlength - 1];
	for (i = maxlength - 1; i >= 0; --i) {
		inverse[i] = array[j];
		j = parent[j];
	}
	/* Imprimir la solución */
	printf("%d\n-\n", maxlength);
	for (i = 0; i < maxlength; ++i)
		printf("%d\n", inverse[i]);

	return 0;
}
