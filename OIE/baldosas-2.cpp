#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int f, c;
    while( cin >> f >> c ) {
        int Combs = 0;
        if( f == 2 ) {
            if( c % 3 == 0 ) Combs = pow( 2, c / 3 );
            else Combs = 0;
        } else {
            if( c % 2 == 0 ) Combs = pow( 2, c / 2 );
            else Combs = 0;
        }

        cout << Combs << endl;
    }

    return 0;
}
