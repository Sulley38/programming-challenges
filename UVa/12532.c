#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000

/* Secuencia inicial */
char seq[MAXN];
/* Segment tree */
char st[4 * MAXN];

/* Construye el árbol que comienza en el nodo p, correspondiente al segmento [L,R] */
void construir(int p, int L, int R) {
	if (L == R) {
		if (seq[L] > 0) st[p] = 1;
		else if (seq[L] < 0) st[p] = -1;
		else st[p] = 0;
	} else {
		int mitad = (L + R) / 2;
		construir(2*p, L, mitad);
		construir(2*p + 1, mitad + 1, R);
		st[p] = st[2*p] * st[2*p + 1];
	}
}

/* Modifica el valor del elemento en la posición I, y todos los segmentos afectados */
void cambiar(int p, int L, int R, int I, int V) {
/* SOLUCIÓN RECURSIVA */
	if (L > I || R < I) return; /*Fuera del intervalo */
	if (L == R) { /* Valor a sustituir */
		if (V > 0) st[p] = 1;
		else if (V < 0) st[p] = -1;
		else st[p] = 0;
		return;
	}
	/* Explorar en el hijo adecuado y actualizar el padre */
	int mitad = (L + R) / 2;
	if (I <= mitad)
		cambiar(2*p, L, mitad, I, V);
	else
		cambiar(2*p + 1, mitad + 1, R, I, V);
	st[p] = st[2*p] * st[2*p + 1];
/* SOLUCIÓN ITERATIVA
	int mitad, camino[20], pasos = 0, i;
	 Buscar la hoja correspondiente al valor a cambiar, guardando el camino
	while (L != I || R != I) {
		camino[pasos++] = p;
		mitad = (L + R) / 2;
		if (I <= mitad) {
			p = 2 * p;
			R = mitad;
		} else {
			p = 2 * p + 1;
			L = mitad + 1;
		}
	}
	 Actualizarla
	if (V > 0) st[p] = 1;
	else if (V < 0) st[p] = -1;
	else st[p] = 0;
	 Actualizar el camino recorrido
	for (i = pasos - 1; i >= 0; --i)
		st[camino[i]] = st[2 * camino[i]] * st[2 * camino[i] + 1]; */
}

/* Consulta el signo de la multiplicación en el intervalo dado */
int consultar(int p, int L, int R, int I, int J) {
	if (L > J || R < I) return 1; /* Fuera del intervalo: devolver el neutro */
	if (L >= I && R <= J) return st[p]; /* Dentro del intervalo */
	/* Explorar en los hijos y devolver el producto */
	int mitad = (L + R) / 2;
	return consultar(2*p, L, mitad, I, J) * consultar(2*p + 1, mitad + 1, R, I, J);
}

/* Devuelve el caracter correspondiente al signo obtenido */
char caracter(int signo) {
	if (signo > 0) return '+';
	if (signo < 0) return '-';
	return '0';
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int N, K, I, J, i, count;
	char c, str[MAXN+1];
	while (scanf("%d %d ", &N, &K) > 0) {
		/* Leer la entrada */
		for (i = 0; i < N; ++i)
			scanf("%d ", (int *)&seq[i]);
		/* Construir el árbol */
		construir(1, 0, N - 1);
		/* Procesar las consultas */
		count = 0;
		for (i = 0; i < K; ++i) {
			scanf("%c %d %d ", &c, &I, &J);
			if (c == 'C')
				cambiar(1, 0, N - 1, I - 1, J);
			else
				str[count++] = caracter(consultar(1, 0, N - 1, I - 1, J - 1));
		}
		str[count] = 0;
		puts(str);
	}

	return 0;
}
