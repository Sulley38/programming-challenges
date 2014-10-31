#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// True si el string s solo tiene caracteres blancos
bool es_blanca( const string& s) {
	return (s.find_first_not_of(' ') == string::npos);
}

// Imprime en salida estándar el string s sin espacios al final
void imprimir( const string& s ) {
	int pos = s.size() - 1;
	while( pos >= 0 && s[pos] == ' ' ) pos--;
	cout << s.substr(0,pos+1) << endl;
}

// Rompe lo más cerca posible a los 72 caracteres, eliminando espacios iniciales en el resultado
// Pre: s.size() > 72
void romper( string& s ) {
	int pos = 72, tamano = s.size();

	// Buscar un espacio donde cortar
	while( pos >= 0 && s[pos] != ' ' ) pos--;
	if( pos == -1 ) {
		// Palabra muy larga, imprimir tal cual y dejar el resto sin espacios
		pos = 72;
		while( pos < tamano && s[pos] != ' ' ) pos++;
		cout << s.substr(0,pos) << endl;

		while( pos < tamano && s[pos] == ' ' ) pos++;
		if( pos == tamano ) s.clear();
		else s = s.substr(pos);
		return;
	}

	// Quitar espacios al resultado e imprimir
	while( pos >= 0 && s[pos] == ' ' ) pos--;
	if( pos == -1 ) {
		// Comienza en espacio y palabra muy larga, o muchos espacios
		// Quitar los espacios (imprimiendo línea en blanco) y volver a intentar romper
		cout << endl;
		pos++;
		while( pos < tamano && s[pos] == ' ' ) pos++;
		if( pos != tamano ) {
			s = s.substr(pos);
			if( s.size() > 72 )
				romper(s);
		}
		return;
	}
	cout << s.substr(0,pos+1) << endl;

	// Dejar en s el otro trozo de string, quitando espacios
	pos++;
	while( pos < tamano && s[pos] == ' ' ) pos++;
	if( pos == tamano ) s.clear();
	else s = s.substr(pos);
}

int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string in, out = "";
	while( getline(cin,in) ) {

		if (es_blanca(in)) {
			// Línea blanca: se conserva el salto de línea anterior
			if (!out.empty())
				imprimir(out);
			imprimir(in);
			out.clear();
		} else if (in[0] == ' ') {
			// Línea comenzado en espacio: se conserva el salto de línea anterior
			if (!out.empty())
				imprimir(out);
			out = in;
		} else {
			if (out.empty()) {
				// Nueva línea
				out = in;
			} else {
				if( out[out.size()-1] == ' ' ) {
					// No se elimina el salto
					imprimir(out);
					out = in;
				} else {
					// Se puede eliminar el salto
					out += " " + in;
				}
			}
		}

		while (out.length() > 72) {
			romper(out);
		}
	}

	if (!out.empty())
		imprimir(out);

	return 0;
}
