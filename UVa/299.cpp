#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n, l, t, i, j, aux, swaps;
	vector<int> trains;
	cin >> n;
	while (n--) {
		trains.clear();
		swaps = 0;

		cin >> l;
		for (i = 0; i < l; ++i) {
			cin >> t;
			trains.push_back(t);
		}

		// Ordenar con bubblesort
		for (i = 1; i <= l; ++i)
			for (j = 0; j < l - 1; ++j)
				if (trains[j] > trains[j+1]) {
					swaps++;
					aux = trains[j];
					trains[j] = trains[j+1];
					trains[j+1] = aux;
				}

		cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
	}

	return 0;
}
