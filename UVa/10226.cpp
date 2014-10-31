#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int c, total;
	cin >> c;
	cin.ignore();
	cin.ignore();

	string s;
	map<string, int> arbol;
	map<string, int>::iterator it;
	while (c--) {
		arbol.clear();
		total = 0;
		s = "a";
		while (getline(cin, s) && s.size() > 0) {
			arbol[s]++;
			total++;
		}
		// Iterar e imprimir
		for (it = arbol.begin(); it != arbol.end(); ++it)
			printf("%s %.4f\n", (it->first).c_str(), ((float)it->second / (float)total) * 100.0);
		if (c)
			puts("");
	}

	return 0;
}
