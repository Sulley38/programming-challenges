#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iValor = 0, iNumeros = 0;
    cin >> iValor >> iNumeros;

    vector<int> vNumeros( iNumeros );
    for( int i = 0; i < iNumeros; i++ ) {
        cin >> vNumeros[i];
    }
    sort( vNumeros.begin(), vNumeros.end() );

    int iCantidad = 0;
    for( int i = 2; i < iNumeros; i++ ) {
        if( vNumeros[0] + vNumeros[1] + vNumeros[i] <= iValor )
            iCantidad++;
    }
    if( iCantidad == 0 )
        cout << "0" << endl;
    else
        cout << iCantidad+2 << endl;

    return 0;
}
