#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, N, caso, ans, i;
	char field[100];
	scanf("%d ", &T);
	for (caso = 1; caso <= T; ++caso) {
		scanf("%d ", &N);
		fgets(field, N + 1, stdin);

		i = ans = 0;
		while (i < N) {
			if (field[i] == '.') {
				ans++;
				i += 3;
			} else {
				i++;
			}
		}

		printf("Case %d: %d\n", caso, ans);
	}

	return 0;
}
