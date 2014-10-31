#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int n, m, t;
	cin >> t;
	while( t-- ) {
		cin >> n >> m;
		cout << (n/3)*(m/3) << endl;
	}
	return 0;
}