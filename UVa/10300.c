#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, f, size, anim, env, cost;
	scanf("%d ", &n);
	while (n--) {
		cost = 0;
		scanf("%d ", &f);
		while (f--) {
			scanf("%d %d %d ", &size, &anim, &env);
			cost += size * env;
		}
		printf("%d\n", cost);
	}
	return 0;
}
