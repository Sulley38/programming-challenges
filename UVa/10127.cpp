#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int minmultiplodeunos( const int& n ) {
	long double test = 11.0;
	int num_digits = 2;
	while( fmod(test,n) != 0 ) {
		test = test*10.0 + 1.0;
		test = fmod(test,n);
		num_digits++;
	}
	return num_digits;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n;
	while( cin >> n )
		cout << minmultiplodeunos(n) << endl;
	return 0;
}
