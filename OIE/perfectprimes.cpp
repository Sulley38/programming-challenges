#include <iostream>

using namespace std;

int SumaDigitos( int Numero )
{
    int Suma = 0;
    while( Numero != 0 ) {
        Suma += Numero % 10;
        Numero /= 10;
    }
    return Suma;
}

bool CheckPrimo( const int& Numero )
{
    for( int i = 2; i < Numero; i++ )
        if( Numero % i == 0 )
            return false;
    return true;
}

int main()
{
    int iNumero, iSuma;

    cin >> iNumero;
    while( iNumero != 0 ) {

        iSuma = SumaDigitos( iNumero );
        if( iSuma == 2 || iSuma == 3 || iSuma == 5 || iSuma == 7 || iSuma == 11 || iSuma == 23 || iSuma == 29 ) {
            if( CheckPrimo( iNumero ) )
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        } else {
            cout << "no" << endl;
        }

        cin >> iNumero;
    }

    return 0;
}
