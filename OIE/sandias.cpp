#include <iostream>

using namespace std;

int main()
{
    int iSandiasA, iCosteA, iSandiasB, iCosteB, iMonedas;
    while( cin >> iSandiasA >> iCosteA >> iSandiasB >> iCosteB >> iMonedas ) {
        int iCompradas = 0;
        if( iCosteA < iCosteB ) {
            if( iMonedas / iCosteA > iSandiasA )
                iCompradas += iSandiasA;
            else
                iCompradas += iMonedas / iCosteA;
            iMonedas -= iCompradas*iCosteA;
            if( iMonedas / iCosteB > iSandiasB )
                iCompradas += iSandiasB;
            else
                iCompradas += iMonedas / iCosteB;
            cout << iCompradas << endl;
        } else {
            if( iMonedas / iCosteB > iSandiasB )
                iCompradas += iSandiasB;
            else
                iCompradas += iMonedas / iCosteB;
            iMonedas -= iCompradas*iCosteB;
            if( iMonedas / iCosteA > iSandiasA )
                iCompradas += iSandiasA;
            else
                iCompradas += iMonedas / iCosteA;
            cout << iCompradas << endl;
        }
    }

    return 0;
}
