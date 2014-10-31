#ifdef TESTING
#include <fstream>
#endif
#include <iostream>
#include <map>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	fstream cout("output.txt");
#endif
	int n, i;
	cin >> n;

	string pais;
	map<string,int> lista;
	for (i = 0; i < n; ++i) {
		cin >> pais;
		cin.ignore(75, '\n');
		lista[pais]++;
	}

	map<string,int>::iterator it;
	for(it = lista.begin(); it != lista.end(); it++)
		cout << it->first << " " << it->second << endl;

	return 0;
}
