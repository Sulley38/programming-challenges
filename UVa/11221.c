#include <stdio.h>
#include <string.h>

#define MAXLEN 10001

int main() {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, i, j, t, read_chars, lado, mitad, magico, pos1, pos2, cuadrados[100] = {1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,9216,9409,9604,9801,10000};
	scanf("%d\n", &t);
	for (a = 1; a <= t; ++a) {
		/* Leer la frase */
		char input[MAXLEN];
		gets(input);
		read_chars = strlen(input);

		/* Quitar signos de puntuación y espacios */
		char frase[read_chars+1];
		unsigned int length = 0;
		for (i = 0; i < read_chars; ++i) {
			frase[length] = input[i];
			if (frase[length] >= 'a' && frase[length] <= 'z')
				length++;
		}
		frase[length] = '\0';

		/* Buscar si la longitud es cuadrado perfecto */
		lado = 0;
		for (i = 0; i < 100; ++i)
			if (cuadrados[i] == length)
				lado = i + 1;

		printf("Case #%d:\n", a);
		if (!lado) {
			puts("No magic :(");
		} else {
			/* Comprobar si encaja en el cuadrado */
			mitad = lado / 2;
			if (mitad * mitad != lado)
				mitad++;
			magico = 1;
			for (i = 0; i < mitad && magico; ++i)
				for (j = i; j < (lado - i) && magico; ++j) {
					pos1 = i * lado + j;
					pos2 = j * lado + i;
					if (frase[pos1] != frase[length-pos1-1] || frase[pos1] != frase[pos2] || frase[pos1] != frase[length-pos2-1])
						magico = 0;
				}

			if (magico)
				printf("%d\n", lado);
			else
				puts("No magic :(");
		}
	}

	return 0;
}
