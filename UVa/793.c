#include <stdio.h>

int root(int *id, int i) {
	while (i != id[i]) {
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

int find(int *id, int p, int q) {
	if (root(id, p) == root(id, q))
		return 1;
	return 0;
}

void make_union(int *id, int *sz, int p, int q) {
	int i = root(id, p), j = root(id, q);
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
	} else {
		id[j] = i;
		sz[i] += sz[j];
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int d, n, i, j, RP, RN;
	char c;

	scanf("%d ", &d);
	while (d--) {
		scanf(" %d ", &n);
		int id[n], sz[n];
		for (i = 0; i < n; ++i) {
			id[i] = i;
			sz[i] = 1;
		}
		RP = RN = 0;

		c = getchar();
		while (c != '\n' && c != EOF) {
			scanf(" %d %d", &i, &j);
			if (c == 'c') {
				/* Conexión */
				make_union(id, sz, i-1, j-1);
			} else {
				/* Pregunta */
				if (find(id, i-1, j-1))
					RP++;
				else
					RN++;
			}
			c = getchar();
			c = getchar();
		}
		printf("%d,%d\n", RP, RN);
		if (d > 0)
			puts("");
	}

	return 0;
}
