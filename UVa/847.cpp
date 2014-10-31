#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	unsigned int n;
	while( cin >> n ) {
		if( n > 612220032 ) cout << "Stan wins." << endl;
		else if( n > 306110016 ) cout << "Ollie wins." << endl;
		else if( n > 34012224 ) cout << "Stan wins." << endl;
		else if( n > 17006112 ) cout << "Ollie wins." << endl;
		else if( n > 1889568 ) cout << "Stan wins." << endl;
		else if( n > 944784 ) cout << "Ollie wins." << endl;
		else if( n > 104976 ) cout << "Stan wins." << endl;
		else if( n > 52488 ) cout << "Ollie wins." << endl;
		else if( n > 5832 ) cout << "Stan wins." << endl;
		else if( n > 2916 ) cout << "Ollie wins." << endl;
		else if( n > 324 ) cout << "Stan wins." << endl;
		else if( n > 162 ) cout << "Ollie wins." << endl;
		else if( n > 18 ) cout << "Stan wins." << endl;
		else if( n > 9 ) cout << "Ollie wins." << endl;
		else cout << "Stan wins." << endl;
	}

	return 0;
}
