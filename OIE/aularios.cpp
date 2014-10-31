#include <iostream>

using namespace std;

int main()
{
    char c, n;
    cin >> c >> n;
    if( c < 'A' || c > 'D' || n < '1' || n > '6' ) {
        cout << "?" << endl;
    } else {
        if( c != 'D' ) cout << char(c + 1) << n << endl;
        else cout << "--" << endl;

        if( n != '6' ) cout << c << char(n + 1) << endl;
        else cout << "--" << endl;

        if( c != 'A' ) cout << char(c - 1) << n << endl;
        else cout << "--" << endl;

        if( n != '1' ) cout << c << char(n - 1) << endl;
        else cout << "--" << endl;
    }

    return 0;
}

