#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int iNumero = 0;
    double dRaiz = 0, dEntero = 0;

    while( cin >> iNumero ) {
        dRaiz = sqrt( iNumero );
        if( modf( dRaiz, &dEntero ) == 0 )
            cout << dRaiz << endl;
        else
            cout << "XXX" << endl;
    }

    return 0;
}
