#include <fstream>
#include <iostream>

using namespace std;

int factorial(const int& n) {
	switch(n) {
	case 0: return 1;
	case 1: return 1;
	case 2: return 2;
	case 3: return 6;
	case 4: return 24;
	case 5: return 120;
	case 6: return 720;
	case 7: return 5040;
	case 8: return 40320;
	case 9: return 362880;
	case 10: return 3628800;
	case 11: return 39916800;
	case 12: return 479001600;
	default: return 1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n, k, i, temp, f;
	while( cin >> n >> k ) {
		f = factorial(n);
		for( i = 0; i < k; ++i ) {
			cin >> temp;
			f /= factorial(temp);
		}
		cout << f << endl;
	}
	return 0;
}
