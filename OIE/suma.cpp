#include <iostream>

using namespace std;

int main()
{
    int m, n;
    while( cin >> m >> n ) {
        if( n >= 0 ) cout << m << "+" << n << "=" << m+n << endl;
        else cout << m << "+(" << n << ")=" << m+n << endl;
    }

    return 0;
}

