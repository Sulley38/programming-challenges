#include <iostream>

using namespace std;

int main()
{
    string s;
    while( cin >> s ) {
        int T = s.size(), SumaP = 0, SumaI = 0;
        // Divisible por 3
        for( int i = 0; i < T; ++i )
            SumaP += s[i]-'0';
        if( SumaP % 3 == 0 ) cout << "1" << endl;
        else cout << "0" << endl;
        // Divisible por 5
        if( s[T-1] == '0' || s[T-1] == '5' ) cout << "1" << endl;
        else cout << "0" << endl;
        // Divisible por 11
        SumaP = 0;
        for( int i = 0; i < T; i += 2 )
            SumaI += s[i]-'0';
        for( int i = 1; i < T; i += 2 )
            SumaP += s[i]-'0';
        if( (SumaI - SumaP) % 11 == 0 ) cout << "1" << endl;
        else cout << "0" << endl;
    }

    return 0;
}
