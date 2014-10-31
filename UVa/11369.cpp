#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int i, t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int precio[n];
		for (i = 0; i < n; ++i)
			cin >> precio[i];
		sort(precio, precio + n);

		int ahorro = 0;
		for (i = n-3; i >= 0; i -= 3)
			ahorro += precio[i];
		cout << ahorro << endl;
	}
	return 0;
}
