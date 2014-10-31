#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1024000

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

/* Segment tree: número de bucaneros en un segmento y operación pendiente */
static int st[4*MAXN];
static char op[4*MAXN];
/* String de entrada */
static char pirate[MAXN];

/* Construye el segment tree con raíz en la posición p, que corresponde al segmento [L,R] */
void construir(int p, int L, int R) {
	if (L == R) { /* Caso básico: segmento de tamaño 1 */
		st[p] = pirate[L] - '0';
		op[p] = 'N';
	} else { /* Caso general: suma de subsegmentos */
		int mitad = (L+R) / 2;
		construir(2*p, L, mitad);
		construir(2*p + 1, mitad + 1, R);
		st[p] = st[2*p] + st[2*p + 1];
		op[p] = 'N';
	}
}

/* Marca la operación en el nodo pos con el valor de new, teniendo en cuenta si se trata de invertir */
void marcar(int pos, char new) {
	if (new == 'I') {
		switch (op[pos]) {
		case 'N': op[pos] = 'I'; break;
		case 'F': op[pos] = 'E'; break;
		case 'E': op[pos] = 'F'; break;
		default: op[pos] = 'N'; break;
		}
	} else {
		op[pos] = new;
	}
}

/* Efectúa la operación en el nodo p y marca sus hijos para ser operados */
void propagar(int p, int L, int R) {
	/* Aplicar la operación pendiente */
	if (op[p] == 'F')
		st[p] = R - L + 1;
	else if (op[p] == 'E')
		st[p] = 0;
	else
		st[p] = R - L + 1 - st[p];
	/* Marcar los hijos pendientes de operar */
	if (L < R) {
		marcar(2*p, op[p]);
		marcar(2*p + 1, op[p]);
	}
	/* Quitar marca del nodo actual */
	op[p] = 'N';
}

/* Consulta sobre todos los subsegmentos comprendidos en [L,R] pertenecientes al subsegmento [A,B].
   Devuelve el número de bucaneros. */
int consultar(int p, int L, int R, int A, int B) {
	if (L > B || R < A) return 0; /* Intervalo totalmente fuera de la consulta */
	if (op[p] != 'N') propagar(p, L, R); /* Aplicar operación pendiente y propagarla */
	if (L >= A && R <= B) return st[p]; /* Intervalo totalmente dentro de la consulta */
	if (st[p] == 0) return 0; /* Ningún bucanero en el segmento */
	if (st[p] == R - L + 1) return min(B, R) - max(A, L) + 1; /* Segmento lleno de bucaneros */
	/* Subdividir y sumar */
	int mitad = (L+R) / 2;
	return consultar(2*p, L, mitad, A, B) + consultar(2*p + 1, mitad + 1, R, A, B);
}

/* Modificar las partes del intervalo [A,B] dentro del intervalo [L,R] según el parámetro c */
void modificar(int p, int L, int R, int A, int B, char c) {
	if (L >= A && R <= B) marcar(p, c); /* Intervalo totalmente dentro de la modificación: marcar operación */
	if (op[p] != 'N') propagar(p, L, R); /* Aplicar operación pendiente y propagarla */
	if (L > B || R < A || (L >= A && R <= B)) return; /* Intervalo totalmente dentro o fuera de la modificación */
	/* Modificar los hijos y actualizar el padre */
	int mitad = (L+R) / 2;
	modificar(2*p, L, mitad, A, B, c);
	modificar(2*p + 1, mitad + 1, R, A, B, c);
	st[p] = st[2*p] + st[2*p + 1];
}

int main(void) {
#ifdef TESTING
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int casos, caso;
	scanf("%d ", &casos);
	for (caso = 1; caso <= casos; ++caso) {
		int N, M, T, Q, a, b, len, consulta;
		char pirates[51], c;
		N = 0;
		/* Leer la entrada */
		scanf("%d ", &M);
		while (M--) {
			scanf("%d %s ", &T, pirates);
			len = strlen(pirates);
			while (T--) {
				strncpy(pirate + N, pirates, len);
				N += len;
			}
		}
		/* Construir el segment tree */
		construir(1, 0, N - 1);
		/* Procesar las consultas */
		scanf("%d ", &Q);
		printf("Case %d:\n", caso);
		consulta = 0;
		while (Q--) {
			scanf("%c %d %d ", &c, &a, &b);
			if (c == 'S')
				printf("Q%d: %d\n", ++consulta, consultar(1, 0, N - 1, a, b));
			else
				modificar(1, 0, N - 1, a, b, c);
		}
	}

	return 0;
}
