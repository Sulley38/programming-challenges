#include <iostream>
#include <string>

using namespace std;
string meses[12] = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };

int main()
{
    int iFechas = 0, iDia = 0, iMes = 0;
    string mes, de;
    cin >> iFechas;

    for( int i = 0; i < iFechas; i++ ) {
        cin >> iDia >> de >> mes;

        while( meses[iMes] != mes ) {
            iMes++;
        }
        iMes++;

        if( iDia == 31 ) {
            iDia = 1;
        }
        else if( iDia == 28 && iMes == 2 ) {
            iDia = 1;
        }
        else if( iDia < 30 ) {
            iDia++;
            iMes--;
        }
        else if( iDia == 30 ) {
            if( iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11 ) {
                iDia = 1;
            } else {
                iDia++;
                iMes--;
            }
        }

        if( iMes == 12 )
            iMes = 0;

        cout << iDia << " de " << meses[iMes] << endl;
        iDia = 0;
        iMes = 0;
    }

    return 0;
}

