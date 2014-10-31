#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void procesar(const string &s1, const unsigned int i1, const string &s2, const unsigned int i2, const string pila, const unsigned int len, string seq) {
	if (i1 == s1.size()) {
		// Comprobar si el orden de output es correcto
		bool correcto = true;
		for (int i = 0; i + i2 < s2.size() && len - i > 0 && correcto; ++i)
			if (s2[i2+i] != pila[len-1-i])
				correcto = false;
			else
				seq += " o";
		// Dar resultado
		if (correcto)
			puts(seq.data());
	} else {
		// Probar a seguir introduciendo en la pila
		procesar(s1, i1 + 1, s2, i2, pila + s1[i1], len + 1, seq + " i");
		// Probar a sacar ahora de la pila, si es posible
		if (len > 0 && pila[len-1] == s2[i2])
			procesar(s1, i1, s2, i2 + 1, pila.substr(0, len - 1), len - 1, seq + " o");
	}
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s1, s2;
	while (getline(cin, s1) && getline(cin, s2)) {
		puts("[");
		if (s1.length() == s2.length())
			procesar(s1, 1, s2, 0, string(1, s1[0]), 1, string("i"));
		puts("]");
	}

	return 0;
}
