#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, i, s1, s2, s3;
	scanf("%d ", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d %d ", &s1, &s2, &s3);
		if ((s1 > s2 && s1 < s3) || (s1 > s3 && s1 < s2))
			printf("Case %d: %d\n", i, s1);
		else if ((s2 > s1 && s2 < s3) || (s2 > s3 && s2 < s1))
			printf("Case %d: %d\n", i, s2);
		else
			printf("Case %d: %d\n", i, s3);
	}
	return 0;
}
