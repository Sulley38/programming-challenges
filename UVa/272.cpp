#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif
	char c;
	bool comillasAbiertas = false;
	while( !cin.eof() ) {
		c = cin.get();
		if( c == 34 ) {
			if( comillasAbiertas ) cout << "''";
			else cout << "``";
			comillasAbiertas = !comillasAbiertas;
		} else if(c != EOF) {
			cout << c;
		}
	}
	return 0;
}
