#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int c, i;
	string linea, s;
	vector<string> texto;
	list<int> orden;
	list<int>::iterator it;

	while (getline(cin, linea)) {
		// Vaciar contenedores
		texto.clear();
		orden.clear();
		orden.push_back(0);
		c = 0;
		// Reordenar el string
		for (i = 0; i < int(linea.size()); ++i) {
			if (linea[i] == '[') {
				texto.push_back(s);
				s.clear();
				orden.push_front(++c);
			} else if (linea[i] == ']') {
				texto.push_back(s);
				s.clear();
				orden.push_back(++c);
			} else {
				s.push_back(linea[i]);
			}
		}
		texto.push_back(s);
		s.clear();
		// Imprimir texto en el orden adecuado
		for (it = orden.begin(); it != orden.end(); ++it)
			cout << texto[*it];
		if (!cin.eof())
			cout << endl;
	}

	return 0;
}
