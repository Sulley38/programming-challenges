#include <stdio.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int b[3], g[3], c[3], min, movs;
	char sol[4];
	while (scanf("%d %d %d %d %d %d %d %d %d ", &b[0], &g[0], &c[0], &b[1], &g[1], &c[1], &b[2], &g[2], &c[2]) > 0) {
		/* BCG */
		min = g[0] + c[0] + b[1] + g[1] + b[2] + c[2];
		strcpy(sol, "BCG");
		/* BGC */
		movs = g[0] + c[0] + b[1] + c[1] + b[2] + g[2];
		if (movs < min) {
			min = movs;
			strcpy(sol, "BGC");
		}
		/* CBG */
		movs = b[0] + g[0] + c[1] + g[1] + b[2] + c[2];
		if (movs < min) {
			min = movs;
			strcpy(sol, "CBG");
		}
		/* CGB */
		movs = b[0] + g[0] + b[1] + c[1] + c[2] + g[2];
		if (movs < min) {
			min = movs;
			strcpy(sol, "CGB");
		}
		/* GBC */
		movs = b[0] + c[0] + c[1] + g[1] + b[2] + g[2];
		if (movs < min) {
			min = movs;
			strcpy(sol, "GBC");
		}
		/* GCB */
		movs = b[0] + c[0] + b[1] + g[1] + c[2] + g[2];
		if (movs < min) {
			min = movs;
			strcpy(sol, "GCB");
		}

		printf("%s %d\n", sol, min);
	}

	return 0;
}
