#include <iostream>

using namespace std;

int main()
{
    int iMensajes = 0;
    cin >> iMensajes;
    cin.ignore( 1 );

    while( iMensajes-- ) {
        string Mns, Res;
        getline( cin, Mns );

        int iLength = Mns.length(), iClave = 'R' - Mns[iLength-2];
        if( iClave < 0 ) {
            iClave += 26;
        }

        for( int i = 0; i < iLength-1; i++ ) {
            Res.push_back( Mns[i] + iClave );
            if( Res[i] > 'Z' )
                Res[i] -= 26;
        }

        cout << Res << endl;
    }

    return 0;
}
