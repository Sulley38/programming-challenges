#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	long long int a, b;
	while (cin >> a >> b)
		cout << ((b > a) ? (b - a) : (a - b)) << endl;
	return 0;
}
