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
	int n, size_div2 = 0;
	bool even = true;
	vector<int> numeros;
	while (cin >> n) {
		numeros.push_back(n);
		if (even) {
			even = false;
		} else {
			even = true;
			size_div2++;
		}
		nth_element(numeros.begin(), numeros.begin() + size_div2, numeros.end());
		if (even) {
			nth_element(numeros.begin(), numeros.begin() + size_div2 - 1, numeros.end());
			cout << (numeros[size_div2] + numeros[size_div2 - 1]) / 2 << endl;
		} else {
			cout << numeros[size_div2] << endl;
		}
	}

	return 0;
}
