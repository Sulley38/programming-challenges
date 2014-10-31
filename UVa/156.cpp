#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
vector<string> palabras, palabras_lower_sorted, palabras_resultado;

bool comp(const int &a, const int &b) {
	return palabras_lower_sorted[a] < palabras_lower_sorted[b];
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s;
	while (cin >> s && s != "#") {
		palabras.push_back(s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		sort(s.begin(), s.end());
		palabras_lower_sorted.push_back(s);
	}

	int size = palabras.size();
	vector<int> ordered_index(size);
	for (int i = 0; i < size; ++i)
		ordered_index[i] = i;
	sort(ordered_index.begin(), ordered_index.end(), comp);

	if (palabras_lower_sorted[ordered_index[0]] != palabras_lower_sorted[ordered_index[1]])
		palabras_resultado.push_back(palabras[ordered_index[0]]);
	for (int i = 1; i < size - 1; ++i)
		if (palabras_lower_sorted[ordered_index[i]] != palabras_lower_sorted[ordered_index[i+1]] && palabras_lower_sorted[ordered_index[i]] != palabras_lower_sorted[ordered_index[i-1]])
			palabras_resultado.push_back(palabras[ordered_index[i]]);
	if (palabras_lower_sorted[ordered_index[size-1]] != palabras_lower_sorted[ordered_index[size-2]])
		palabras_resultado.push_back(palabras[ordered_index[size-1]]);
	sort(palabras_resultado.begin(), palabras_resultado.end());

	for (unsigned int i = 0; i < palabras_resultado.size(); ++i)
		cout << palabras_resultado[i] << endl;

	return 0;
}
