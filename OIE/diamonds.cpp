#include <iostream>

using namespace std;

int main()
{
    int iValor = 0, iDiamantes = 0, iCurrent = 0;

    while( cin >> iValor >> iDiamantes ) {
        cin.ignore( 64, '\n' );

        if( iValor != 0 || iDiamantes != 0 ) {
            int vDiamantes[iDiamantes];
            bool bRegalo = false;

            for( int i = 0; i < iDiamantes; i++ ) {
                cin >> iCurrent;
                vDiamantes[i] = iCurrent;
                for( int j = 0; j < i; j++ ) {
                    if( iCurrent + vDiamantes[j] == iValor )
                        bRegalo = true;
                }
            }

            if( bRegalo )
                cout << "married" << endl;
            else
                cout << "single" << endl;

        } else {
            break;
        }

    }

    return 0;
}
