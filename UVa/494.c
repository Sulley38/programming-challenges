#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int count, word, i;
	char line[512];
	while (gets(line)) {
		count = word = 0;
		for (i = 0; line[i] != 0; ++i) {
			if (!word && ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))) {
				word = 1;
				count++;
			} else if (word && (line[i] < 'A' || (line[i] > 'Z' && line[i] < 'a') || line[i] > 'z')) {
				word = 0;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
