#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int power2[] = {0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823,2147483647};
	int length, ans, i;
	char n[33];

	while (scanf("%s%n ", n, &length) > 0 && n[0] != '0') {
		ans = 0;
		i = 1;
		while (length >= i) {
			ans += (n[length - i] - '0') * power2[i];
			i++;
		}
		printf("%d\n", ans);
	}

	return 0;
}
