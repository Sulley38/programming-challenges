#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string letras = "A---3--HIL-JM-O---2TUVWXY5", numeros = "1SE-Z--8-";

bool es_palindromo( const string& a ) {
	return (a == string( a.rbegin(), a.rend() ));
}

bool es_mirrored( const string& a ) {
	int tam = a.size();
	for( int i = 0; i <= tam/2; ++i ) {
		if( (a[i] >= 'A' && a[i] <= 'Z' && letras[a[i]-'A'] != a[tam-1-i]) ||
			(a[i] >= '1' && a[i] <= '9' && numeros[a[i]-'1'] != a[tam-1-i]) )
			return false;
	}
	return true;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif
	string s;
	bool pal, mir;
	while( cin >> s ) {
		pal = es_palindromo(s);
		mir = es_mirrored(s);
		if( !pal && !mir )
			cout << s << " -- is not a palindrome." << endl << endl;
		else if( pal && !mir )
			cout << s << " -- is a regular palindrome." << endl << endl;
		else if( !pal && mir )
			cout << s << " -- is a mirrored string." << endl << endl;
		else
			cout << s << " -- is a mirrored palindrome." << endl << endl;
	}
	return 0;
}
