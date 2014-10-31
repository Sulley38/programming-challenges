#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int count = 0, i, j, n, p;
	string s;
	map<string,int> requisito;

	while (cin >> n >> p && (n != 0 || p != 0)) {
		requisito.clear();
		cin.ignore();
		// Leer requisitos
		for (i = 0; i < n; ++i) {
			getline(cin, s);
			requisito[s] = i;
		}
		// Leer propuestas
		vector<string> nombre(p);
		vector<double> precio(p);
		vector<int> reqcumplidos(p);
		for (i = 0; i < p; ++i) {
			// Nombre
			getline(cin, s);
			nombre[i] = s;
			// Precio y núm. requisitos satisfechos
			cin >> precio[i] >> reqcumplidos[i];
			cin.ignore();
			// Requisitos satisfechos
			for (j = 0; j < reqcumplidos[i]; ++j)
				getline(cin, s);
		}
		// Elegir la mejor propuesta
		int mejor = 0;
		for (i = 1; i < p; i++)
			if (reqcumplidos[i] > reqcumplidos[mejor] || (reqcumplidos[i] == reqcumplidos[mejor] && precio[i] < precio[mejor]))
				mejor = i;

		if (count > 0) cout << endl;
		cout << "RFP #" << ++count << endl;
		cout << nombre[mejor] << endl;
	}

	return 0;
}
