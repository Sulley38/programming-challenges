#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iPersonas = 0;
    cin >> iPersonas;

    vector<int> vHombres(iPersonas), vMujeres(iPersonas);
    for( int i = 0; i < iPersonas; i++ ) {
        cin >> vHombres[i];
    } for( int i = 0; i < iPersonas; i++ ) {
        cin >> vMujeres[i];
    }

    sort( vHombres.begin(), vHombres.end() );
    sort( vMujeres.begin(), vMujeres.end() );

    int iMinimo = 0, iMaximo = 0;
    for( int i = 0; i < iPersonas; i++ ) {
        iMinimo += abs( vHombres[i] - vMujeres[i] );
        iMaximo += abs( vHombres[i] - vMujeres[iPersonas-1-i] );
    }
    cout << iMinimo << " " << iMaximo << endl;

    return 0;
}
