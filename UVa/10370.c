#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int C, N, marks[1000], i;
	double sum, avg, count;
	scanf("%d ", &C);
	while (C--) {
		scanf("%d ", &N);

		/* Calcular nota media */
		sum = 0;
		for (i = 0; i < N; ++i) {
			scanf("%d ", &marks[i]);
			sum += marks[i];
		}
		avg = sum / N;

		/* Contar estudiantes por encima */
		count = 0;
		for (i = 0; i < N; ++i)
			if (marks[i] > avg)
				count++;

		printf("%.3f%%\n", count * 100.0 / N);
	}
	return 0;
}
