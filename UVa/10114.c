#include <stdio.h>

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int months, records;
	double payment, owe;
	while (scanf("%d %lf %lf %d ", &months, &payment, &owe, &records) > 0 && months >= 0) {
		int month[records], i, mes = 0;
		double depreciation[records], value = owe + payment, plazo = owe / months;
		for (i = 0; i < records; ++i)
			scanf("%d %lf ", &month[i], &depreciation[i]);
		/* Simulación mes a mes */
		i = 0;
		value -= depreciation[i] * value; /* Mes 0 */
		/*printf("Mes %d: %lf %lf\n", mes, owe, value);*/
		while (owe >= value) {
			mes++;
			if (i + 1 < records && month[i+1] == mes) i++;
			value -= depreciation[i] * value;
			owe -= plazo;
			/*printf("Mes %d: %lf %lf\n", mes, owe, value);*/
		}
		/* Resultado */
		if (mes == 1)
			puts("1 month");
		else
			printf("%d months\n", mes);
	}
	return 0;
}
