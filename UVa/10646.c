#include <stdio.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, i, t, y, p;
	char valor[52], palo[52];
	scanf("%d\n", &t);
	for (a = 1; a <= t; ++a) {
		for (i = 0; i < 52; ++i)
			scanf("%c%c ", &valor[i], &palo[i]);

		y = 0, p = 26;
		for (i = 0; i < 3; ++i) {
			if (valor[p] == 'A' || valor[p] == 'K' || valor[p] == 'Q' || valor[p] == 'J') {
				y += 10;
				p -= 1;
			} else {
				y += valor[p] - '0';
				p -= 10 - (valor[p] - '0') + 1;
			}
		}

		if (y - 1 <= p)
			printf("Case %d: %c%c\n", a, valor[y-1], palo[y-1]);
		else
			printf("Case %d: %c%c\n", a, valor[26+y-p-1], palo[26+y-p-1]);
	}

	return 0;
}
