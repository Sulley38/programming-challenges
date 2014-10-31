#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define divc(a, b) (a / b + (a % b ? 1 : 0))

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	long long int n, m, a;
	scanf("%I64d %I64d %I64d ", &n, &m, &a);
	printf("%I64d\n", divc(n, a) * divc(m, a));
	return 0;
}
