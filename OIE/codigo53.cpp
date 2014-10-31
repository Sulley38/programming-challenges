#include <iostream>
#include <vector>

using namespace std;

char Asociacion( const int& i ) {
    if( i <= 25 ) return 'A' + i;
    else if( i == 26 ) return '_';
    else return 'z' - i + 27;
}

int Codif( const string& e ) {
    vector<int> c(4);
    for( int i = 0; i < 4; i++ ) {
        if( e[i] >= 'A' && e[i] <= 'Z' ) c[i] = e[i] - 'A';
        else if( e[i] >= 'a' && e[i] <= 'z' ) c[i] = - ( e[i] - 'z' ) + 27;
        else c[i] = 26;
    }
    return c[2] + 53*c[1] + 53*53*c[3] + 53*53*53*c[0];
}

string Descodif( const int& n ) {
    string res;
    res.push_back( Asociacion( n / 53 / 53 / 53 % 53 ) );
    res.push_back( Asociacion( n / 53 % 53 ) );
    res.push_back( Asociacion( n % 53 ) );
    res.push_back( Asociacion( n / 53 / 53 % 53 ) );
    return res;
}

int main()
{
    string op;
    cin >> op;
    if( op == "codifica" ) {
        string s; cin >> s;
        while( int(s.size()) % 4 != 0 ) s.push_back( '_' );
        for( int i = 0; i < int(s.size()); i += 4 ) cout << Codif( s.substr( i, 4 ) ) << endl;
    } else {
        string o;
        int n;
        while( cin >> n ) o += Descodif( n );
        cout << o << endl;
    }

    return 0;
}
