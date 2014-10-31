#include <stdio.h>
#include <string.h>

void diff(char* buffer, const int i, const int j) {
	char a[16], b[16];
	sprintf(a, "%d", i);
	sprintf(b, "%d", j);
	int k = 0;
	while (a[k] == b[k]) k++;
	strcpy(buffer, b+k);
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, caso = 1, i, num, lastnum, first, last;
	char buf[16];
	while (scanf("%d ", &n) > 0 && n > 0) {
		printf("Case %d:\n", caso++);
		num = first = last = 0;
		for (i = 0; i < n; ++i) {
			getchar();
			lastnum = num;
			scanf("%d ", &num);
			if (num == lastnum + 1) {
				/* Añadir a la secuencia */
				last++;
			} else {
				/* Imprimir secuencia y empezar nueva */
				if (first != 0 && first != last) {
					diff(buf, first, last);
					printf("0%d-%s\n", first, buf);
				} else if (first != 0 && first == last) {
					printf("0%d\n", first);
				}
				first = num;
				last = first;
			}
		}
		/* Imprimir último número/secuencia */
		if (first != last) {
			diff(buf, first, last);
			printf("0%d-%s\n", first, buf);
		} else if (first == last) {
			printf("0%d\n", first);
		}
		puts("");
	}

	return 0;
}
