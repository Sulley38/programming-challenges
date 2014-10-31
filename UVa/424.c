#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sumar(char * out, int * length, const char * in, int last) {
	int i = 0, c = 0;
	while (i <= last) {
		out[i] += in[last - i] - '0' + c;
		if (out[i] > 9) {
			out[i] -= 10;
			c = 1;
		} else {
			c = 0;
		}
		i++;
	}
	while (c) {
		out[i]++;
		if (out[i] > 9) {
			out[i] -= 10;
		} else {
			c = 0;
		}
		i++;
	}
	if (i > *length)
		*length = i;
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int length = 1;
	char n[101], sum[103];
	memset(sum, 0, sizeof sum);
	scanf("%s ", n);
	while (n[0] != '0' || n[1] != 0) {
		sumar(sum, &length, n, strlen(n) - 1);
		scanf("%s ", n);
	}
	while (length--)
		putchar(sum[length] + '0');
	putchar('\n');
	return 0;
}
