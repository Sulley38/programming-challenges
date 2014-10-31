#include <stdio.h>

int maxsuma, optimo, n, t;

/* Elegir de las pistas 'ultima' en adelante, habiendo elegido hasta ahora 'seleccion'
   que acumula 'suma' de duración */
void elegir(int * duracion, int suma, int seleccion, int ultima) {
	int i;
	for (i = ultima + 1; i < t; ++i) {
		if (suma + duracion[i] <= n) { /* Elegir el i-ésimo */
			if (suma + duracion[i] > maxsuma) { /* Guardar la mejor combinación encontrada */
				maxsuma = suma + duracion[i];
				optimo = seleccion | (1 << i);
			}
			elegir(duracion, suma + duracion[i], seleccion | (1 << i), i);
		}
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	while (scanf("%d %d ", &n, &t) > 0) {
		int i, duracion[t];
		for (i = 0; i < t; ++i)
			scanf("%d ", &duracion[i]);
		maxsuma = optimo = 0;
		elegir(duracion, 0, 0, -1);
		for (i = 0; i < t; ++i)
			if (optimo & (1 << i))
				printf("%d ", duracion[i]);
		printf("sum:%d\n", maxsuma);
	}

	return 0;
}
