#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n;
	cin >> n;
	cin.ignore();
	cin.ignore();
	string s;
	vector<string> frases, frases_ord, parejas;
	while (n--) {
		frases.clear();
		frases_ord.clear();
		while (getline(cin, s) && s != "") {
			frases.push_back(s);
			sort(s.begin(), s.end());
			while (s[0] == ' ') // Trim
				s.erase(s.begin());
			frases_ord.push_back(s);
		}

		// Comprobar los anagramas
		parejas.clear();
		int size = frases_ord.size();
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				if (frases_ord[i] == frases_ord[j]) {
					if (frases[i] < frases[j])
						parejas.push_back(frases[i] + " = " + frases[j]);
					else
						parejas.push_back(frases[j] + " = " + frases[i]);
				}

			}
		}
		sort(parejas.begin(), parejas.end());

		// Output
		for (unsigned int i = 0; i < parejas.size(); ++i)
			cout << parejas[i] << endl;
		if (n > 0)
			cout << endl;
	}

	return 0;
}
