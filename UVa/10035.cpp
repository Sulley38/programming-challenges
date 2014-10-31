#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int llevadas( const string& a, const string& b ) {
	int carry = 0, count = 0, sum;
	for( int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0; --i, --j ) {
		if( i >= 0 && j >= 0 )
			sum = a[i]-'0' + b[j]-'0' + carry;
		else if( i >= 0 )
			sum = a[i]-'0' + carry;
		else
			sum = b[j]-'0' + carry;

		if( sum > 9 ) {
			carry = 1;
			count++;
		} else {
			carry = 0;
		}
	}
	return count;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int res;
	string s1, s2;
	while( cin >> s1 >> s2 && (s1 != "0" || s2 != "0") ) {
		res = llevadas(s1,s2);
		if( res == 0 )
			cout << "No carry operation." << endl;
		else if( res == 1 )
			cout << "1 carry operation." << endl;
		else
			cout << res << " carry operations." << endl;
	}

	return 0;
}
