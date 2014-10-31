#ifdef TESTING
#include <fstream>
#endif
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n, b, h, w, p, i, j, beds;
	while (cin >> n >> b >> h >> w) {
		int min_cost = b + 1;
		for (i = 0; i < h; ++i) {
			cin >> p;
			bool posible = false;
			for (j = 0; j < w; ++j) {
				cin >> beds;
				if (beds >= n)
					posible = true;
			}

			if (posible && p * n < min_cost)
				min_cost = p * n;
		}

		if (min_cost != b + 1)
			cout << min_cost << endl;
		else
			cout << "stay home" << endl;
	}

	return 0;
}
