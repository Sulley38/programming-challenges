#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool palindromo( const string& s ) {
	int tam = s.size();
	for( int i = 0; i < tam/2; ++i )
		if( s[i] != s[tam-1-i] )
			return false;
	return true;
}

string invertir( const string& s ) {
	return string(s.rbegin(),s.rend());
}

string suma( const string& a, const string& b ) {
	string c;
	int carry = 0, sum;
	for( int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0; --i, --j ) {
		if( i >= 0 && j >= 0 )
			sum = a[i]-'0' + b[j]-'0' + carry;
		else if( i >= 0 )
			sum = a[i]-'0' + carry;
		else
			sum = b[j]-'0' + carry;

		if( sum > 9 )
			carry = 1;
		else
			carry = 0;
		c.push_back((sum%10)+'0');
	}
	if( carry == 1 ) c.push_back('1');
	return string(c.rbegin(),c.rend());
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n, pasos;
	cin >> n;
	string num;
	while( n-- ) {
		cin >> num;
		pasos = 0;
		while( !palindromo(num) ) {
			num = suma( num, invertir(num) );
			pasos++;
		}
		cout << pasos << " " << num << endl;
	}

	return 0;
}
