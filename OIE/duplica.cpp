#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iCasosdePrueba = 0, iPrimerNumero = 0;
    vector<int> iNumero(100);

    cin >> iCasosdePrueba;

    for( int i = 0; i < iCasosdePrueba; i++ )
    {
        cin >> iPrimerNumero;
        if( iPrimerNumero > 0 )
        {
            for( int j = 0; j < iPrimerNumero-1 ; j++ )
            {
                cin >> iNumero[j];
                cout << iNumero[j]*2 << " ";
            }
            cin >> iNumero[0];
            cout << iNumero[0]*2;
            iNumero.empty();
        }
        cout << endl;
    }

    return 0;
}
