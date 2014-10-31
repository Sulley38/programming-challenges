#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Comprueba si desde V[i] hasta -V[i] hay una matrioska válida.
// Devuelve la posición siguiente a donde se encuentra -V[i], o -1 si no es válida.
int check(const vector<int>& V, int i) {
	int j = i + 1, size = 0;
	if (j >= int(V.size()) || V[i] > 0)
		return -1;
	while (V[j] != -V[i]) {
		j = check(V, j);
		if (j == -1)
			return -1;
		size += V[j-1];
		if (size >= -V[i])
			return -1;
	}
	return j + 1;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int i;
	string s;
	vector<int> values;
	while (getline(cin, s)) {
		values.clear();
		istringstream ss(s);
		while (ss >> i)
			values.push_back(i);

		i = check(values, 0);
		while (i > 0 && i < int(values.size()))
			i = check(values, i);

		if (i > 0)
			puts(":-) Matrioshka!");
		else
			puts(":-( Try again.");
	}

	return 0;
}
