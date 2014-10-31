#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector<int> > Numeros( 31, vector<int>( 31 ) );
    for( int n = 0; n < 31; n++ ) {
        Numeros[n][0] = 1;
        Numeros[n][n] = 1;
    }

    for( int n = 1; n < 31; n++ )
        for( int k = 1; k < n; k++ )
            Numeros[n][k] = Numeros[n-1][k-1] + Numeros[n-1][k];

    int iN, iK;
    while( cin >> iN >> iK )
        cout << Numeros[iN][iK] << endl;

    return 0;
}
