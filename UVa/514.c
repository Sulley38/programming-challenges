#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, ord[1000], station[1000], a_in, st_in, ord_in;
	while (scanf("%d ", &N) > 0 && N != 0) {
		while (scanf("%d ", &ord[0]) > 0 && ord[0] != 0) {
			/* Procesar caso */
			for (ord_in = 1; ord_in < N; ++ord_in)
				scanf("%d ", &ord[ord_in]);
			a_in = 1, st_in = -1, ord_in = 0;

			while (ord_in < N) {
				if (st_in >= 0 && ord[ord_in] == station[st_in]) {
					ord_in++;
					st_in--;
				} else if (ord[ord_in] == a_in) {
					ord_in++;
					a_in++;
				} else if (a_in <= N) {
					station[++st_in] = a_in++;
				} else {
					ord_in = N + 1;
				}
			}

			if (ord_in == N)
				puts("Yes");
			else
				puts("No");
		}
		puts("");
	}


	return 0;
}
