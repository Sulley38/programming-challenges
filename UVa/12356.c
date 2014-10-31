#include <stdio.h>
#include <string.h>

#define MAX 100001

static int leftb[MAX], rightb[MAX];

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int s, olds = MAX, b, l, newl, r, newr, i;
	while (scanf("%d %d ", &s, &b) > 0 && (s != 0 || b != 0)) {
		memset(leftb + 1, 0, olds * sizeof (int));
		memset(rightb + 1, 0, olds * sizeof (int));
		leftb[1] = -1;
		rightb[s] = -1;

		for (i = 0; i < b; ++i) {
			scanf("%d %d ", &l, &r);

			if (leftb[l] == 0)
				newl = l - 1;
			else
				newl = leftb[l];
			if (rightb[r] == 0)
				newr = r + 1;
			else
				newr = rightb[r];
			/* Imprimir nuevos extremos */
			if (leftb[l] == -1 && rightb[r] == -1)
				puts("* *");
			else if (leftb[l] == -1)
				printf("* %d\n", newr);
			else if (rightb[r] == -1)
				printf("%d *\n", newl);
			else
				printf("%d %d\n", newl, newr);
			/* Reasignar compañeros */
			if (newl != -1)
				rightb[newl] = newr;
			if (newr != -1)
				leftb[newr] = newl;
		}

		puts("-");
		olds = s;
	}

	return 0;
}
