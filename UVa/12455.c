#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, n, p, L[20];
	int Choose[20], Last, Sum;
	int i;
	scanf("%d ", &t);
	while (t--) {
		/* Leer la entrada */
		scanf("%d %d ", &n, &p);
		for (i = 0; i < p; ++i)
			scanf("%d ", &L[i]);
		/* Calcular las combinaciones */
		qsort(L, p, sizeof(int), compare);
		Choose[0] = 0;
		Last = 0;
		Sum = L[0];
		while (Last >= 0 && Sum < n) {
			if (Last < p && Choose[Last] < p - 1 && Sum + L[Choose[Last] + 1] <= n) {
				/* Coger un trozo más */
				Last++;
				Choose[Last] = Choose[Last - 1] + 1;
				Sum += L[Choose[Last]];
			} else if (Choose[Last] < p - 1 && Sum - L[Choose[Last]] + L[Choose[Last] + 1] <= n) {
				/* Avanzar el último trozo cogido */
				Sum -= L[Choose[Last]];
				Choose[Last]++;
				Sum += L[Choose[Last]];
			} else {
				/* Quitar el último trozo cogido y avanzar el anterior */
				Sum -= L[Choose[Last]];
				Last--;
				if (Last >= 0) {
					Sum -= L[Choose[Last]];
					Choose[Last]++;
					Sum += L[Choose[Last]];
				}
			}
		}
		/* Imprimir resultado */
		if (Sum == n || n == 0)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
