#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int v, t;
	while (cin >> v >> t)
		cout << 2 * v * t << endl;
	return 0;
}
