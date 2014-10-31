#include <stdio.h>
#include <stdlib.h>

int count[26] = {0};

int compare (const void *a, const void *b) {
	if (count[*(int*)a] == count[*(int*)b])
		return (*(int*)a - *(int*)b);
	return (count[*(int*)b] - count[*(int*)a]);
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, i;
	char line[256];

	gets(line);
	n = atoi(line);
	while (n--) {
		gets(line);
		for (i = 0; line[i] != 0; ++i) {
			if (line[i] >= 'a' && line[i] <= 'z')
				count[line[i] - 'a']++;
			else if (line[i] >= 'A' && line[i] <= 'Z')
				count[line[i] - 'A']++;
		}
	}

	int ord[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	qsort(ord, 26, sizeof(int), compare);

	for (i = 0; i < 26; ++i) {
		if (count[ord[i]] > 0)
			printf("%c %d\n", ord[i] + 'A', count[ord[i]]);
		else
			i = 26;
	}

	return 0;
}
