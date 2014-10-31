#include <stdio.h>
#include <string.h>

#define NEGRO 1
#define BLANCO 0

int n;
int G[100][100];
int vecinos[100], pintados[100];
char color[100];
int maximo;
int optimo[100];

/* Comprueba si el nodo podría pintarse de negro cumpliendo las restricciones del problema */
int posibleNegro(int nodo) {
	int i;
	for (i = 0; i < vecinos[nodo]; ++i)
		if (color[G[nodo][i]] == NEGRO)
			return 0;
	return 1;
}

void pintar(int ultimo, int negros, int blancos) {
	if (ultimo+1 == n) {
		if (negros > maximo) {
			maximo = negros;
			/* Guardar la lista de nodos negros */
			int i, j = 0;
			for (i = 0; i < 100; ++i)
				if (color[i] == NEGRO)
					optimo[j++] = i+1;
		}
	} else if (n - blancos > maximo) { /* Seguir probando si hay perspectivas de mejorar */
		/* Intentar el ultimo+1 de negro */
		if (color[ultimo+1] < 0 && posibleNegro(ultimo+1)) {
			color[ultimo+1] = NEGRO;
			int i;
			for (i = 0; i < vecinos[ultimo+1]; ++i)
				if (color[G[ultimo+1][i]] < 0)
					color[G[ultimo+1][i]] = BLANCO;
			pintar(ultimo+1, negros+1, blancos);
		}
		/* Intentarlo de blanco */
		color[ultimo+1] = BLANCO;
		pintar(ultimo+1, negros, blancos+1);
		color[ultimo+1] = -1;
	}
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m, k, a, b;
	scanf("%d ", &m);
	while (m--) {
		maximo = 0;
		memset(vecinos, 0, sizeof vecinos);
		memset(color, -1, sizeof color);
		scanf("%d %d ", &n, &k);
		while (k--) {
			/* Leer las aristas */
			scanf("%d %d ", &a, &b);
			G[a-1][vecinos[a-1]] = b-1;
			G[b-1][vecinos[b-1]] = a-1;
			vecinos[a-1]++, vecinos[b-1]++;
		}
		/* Comenzar la búsqueda */
		pintar(-1, 0, 0);
		/* Imprimir el resultado */
		printf("%d\n", maximo);
		int i;
		for (i = 0; i < maximo-1; ++i)
			printf("%d ", optimo[i]);
		printf("%d\n", optimo[maximo-1]);
	}

	return 0;
}
