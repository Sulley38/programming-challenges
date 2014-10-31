#include <stdio.h>

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i, e, balance, caso = 0;
	scanf("%d", &n);
	while (n != 0) {
		caso++;
		balance = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &e);
			if (e == 0)
				balance--;
			else
				balance++;
		}
		printf("Case %d: %d\n", caso, balance);
		scanf("%d", &n);
	}
	return 0;
}
