#include <iostream>
#include <vector>

#define SIZE 1000000

using namespace std;

int main()
{
    vector<int> Steps(SIZE);
    int m, n;
    while( cin >> m >> n ) {
        int Res = 0, Cuenta;
        long long Test;
        for( int i = min(m,n); i <= max(m,n); ++i ) {
            Test = i;
            Cuenta = 1;
            while( Test != 1 ) {
                if( Test < SIZE && Steps[Test] != 0 ) {
                    Cuenta += Steps[Test]-1;
                    Test = 1;
                } else {
                    if( Test%2 == 0 )
                        Test /= 2;
                    else
                        Test = 3*Test + 1;
                    Cuenta++;
                }
            }
            Steps[i] = Cuenta;
            if( Cuenta > Res ) Res = Cuenta;
        }
        cout << m << " " << n << " " << Res << endl;
    }

    return 0;
}
