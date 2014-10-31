#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

char pagina[60][60];
string C5[5] = {
".***..****...****.****..*****.*****..****.*...*.*****...***.*...*.*.....*...*.*...*..***..****...***..****...****.*****.*...*.*...*.*...*.*...*.*...*.*****.",
"*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*......*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*.*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*..",
"*****.****..*.....*...*.***...***...*..**.*****...*......*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****...***....*...*...*..*.*..*.*.*...*.....*.....*...",
"*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*...*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*......*...*...*...*..*.*..**.**..*.*....*....*....",
"*...*.****...****.****..*****.*......***..*...*.*****..**...*...*.*****.*...*.*...*..***..*......****.*...*.****...***...***....*...*...*.*...*...*...*****."};

// Pinta el texto de izquierda a derecha en la posición indicada
void colocar_texto_izq(string T, int R, int C, bool C1) {
	int size = T.size();
	if (C1) {
		for (int c = 0; c < size && C+c < 60; ++c)
			if (T[c] != ' ')
				pagina[R][C+c] = T[c];
	} else {
		for (int c = 0; c < size && C+6*c < 60; ++c)
			if (T[c] != ' ')
				for (int i = 0; i < 5 && R+i < 60; ++i)
					for (int j = 0; j < 6 && C+6*c+j < 60; ++j)
						if (C5[i][(T[c]-'A')*6+j] != '.')
							pagina[R+i][C+6*c+j] = C5[i][(T[c]-'A')*6+j];
	}
}

// Pinta el texto de derecha a izquierda en la fila indicada
void colocar_texto_der(string T, int R, bool C1) {
	int size = T.size();
	if (C1) {
		for (int c = 0; c < size && 59-c >= 0; ++c)
			if (T[size-1-c] != ' ')
				pagina[R][59-c] = T[size-1-c];
	} else {
		for (int c = 0; c < size && 59-6*c >= 0; ++c)
			if (T[size-1-c] != ' ')
				for (int i = 0; i < 5 && R+i < 60; ++i)
					for (int j = 0; j < 6 && 59-6*c-j >= 0; ++j)
						if (C5[i][(T[size-1-c]-'A')*6+5-j] != '.')
							pagina[R+i][59-6*c-j] = C5[i][(T[size-1-c]-'A')*6+5-j];
	}
}

// Pinta el texto centrado en la fila indicada
void colocar_texto_cen(string T, int R, bool C1) {
	int size = T.size();
	if (C1) {
		int C = 30 - size / 2;
		for (int c = 0; c < size && C+c < 60; ++c)
			if (T[c] != ' ' && C+c >= 0)
				pagina[R][C+c] = T[c];
	} else {
		int C = 30 - size * 3;
		for (int c = 0; c < size && C+6*c < 60; ++c)
			if (T[c] != ' ' && C+6*c+5 >= 0)
				for (int i = 0; i < 5 && R+i < 60; ++i)
					for (int j = 0; j < 6 && C+6*c+j < 60; ++j)
						if (C5[i][(T[c]-'A')*6+j] != '.' && C+6*c+j >= 0)
							pagina[R+i][C+6*c+j] = C5[i][(T[c]-'A')*6+j];
	}
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int fila, columna;
	char c;
	string comando, fuente, texto;
	// Inicializar en blanco
	memset(pagina, '.', sizeof pagina);
	// Procesar comandos
	while (cin >> comando) {
		if (comando == ".EOP") {
			// Output
			for (int i = 0; i < 60; ++i) {
				for (int j = 0; j < 60; ++j)
					printf("%c", pagina[i][j]);
				printf("\n");
			}
			puts("\n------------------------------------------------------------\n");
			memset(pagina, '.', sizeof pagina);
		} else {
			texto.clear();
			// Leer operandos
			cin >> fuente >> fila;
			if (comando == ".P")
				cin >> columna;
			while ((c = cin.get()) != '|');
			while ((c = cin.get()) != '|')
				texto.push_back(c);
			// Realizar operación
			if (comando == ".P")
				colocar_texto_izq(texto, fila - 1, columna - 1, fuente == "C1");
			else if (comando == ".L")
				colocar_texto_izq(texto, fila - 1, 0, fuente == "C1");
			else if (comando == ".R")
				colocar_texto_der(texto, fila - 1, fuente == "C1");
			else if (comando == ".C")
				colocar_texto_cen(texto, fila - 1, fuente == "C1");
		}
	}

	return 0;
}
