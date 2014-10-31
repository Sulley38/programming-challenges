#include <iostream>

using namespace std;

int main()
{
    int iFilas, iColumnas, iNumero = 0;
    cin >> iFilas >> iColumnas;

    for( int i = 0; i < iFilas; i++ )
    {
        for( int j = 0; j < iColumnas; j++ )
        {
            if( iColumnas - j <= iNumero ) {
                iNumero--;
                cout << iNumero;
            } else if( i > iNumero && iFilas - i - 1 > iNumero ) {
                cout << iNumero;
                iNumero++;
            } else {
                cout << iNumero;
            }
        }
        cout << endl;
    }

    return 0;
}
