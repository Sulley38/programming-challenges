#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Devuelve la posición en la que termina el slump, o -1 si no lo hay
int ParseSlump( const string& s ) {
	if( s.size() < 3 ) return -1;
	unsigned int index = 0;
	if( s[index] != 'D' && s[index] != 'E' ) return -1;
	index++;
	while( index < s.size() && s[index] == 'F' ) index++;
	if( index == s.size() || s[index-1] != 'F' ) return -1;

	if( s[index] == 'G' ) return index+1; // Slump correcto
	else index += ParseSlump( s.substr(index) ); // SubSlump

	return index;
}

// Devuelve la posición en la que termina el slimp, o -1 si no lo hay
int ParseSlimp( const string& s ) {
	if( s.size() < 2 ) return -1;
	unsigned int index = 0;
	if( s[index] != 'A' ) return -1;
	index++;
	if( s[index] == 'H' ) {
		return index+1; // 2, Slimp correcto
	} else {
		if( s[index] == 'B' ) {
			index++;
			index += ParseSlimp( s.substr(index) );
			if( index < s.size() && s[index] == 'C' )
				return index+1; // AB(Slimp)C, Slimp correcto
		} else {
			index += ParseSlump( s.substr(index) );
			if( index < s.size() && s[index] == 'C' )
				return index+1; // A(Slump)C, Slimp correcto
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif

	int n, pos, pos2;
	cin >> n;

	cout << "SLURPYS OUTPUT" << endl;

	vector<string> Input(n);
	for( int i = 0; i < n; ++i ) {
		cin >> Input[i];
		pos = ParseSlimp( Input[i] );
		if( pos > 0 ) {
			pos2 = ParseSlump( Input[i].substr(pos) );
			if( pos + pos2 == int(Input[i].size()) )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}
