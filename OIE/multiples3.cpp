#include <iostream>
#include <sstream>

using namespace std;
string Sumar( const string& s );

int main()
{
    string n;
    while( cin >> n ) {
        while( int(n.size()) > 1 ) n = Sumar( n );
        if( n[0] == '3' || n[0] == '6' || n[0] == '9' ) cout << "Ok" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

string Sumar( const string& s ) {
    int res = 0;
    for( int i = 0; i < int(s.size()); i++ ) {
        res += s[i] - '0';
    }

    ostringstream oss;
    oss << res;
    return oss.str();
}
