#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iAncho = 0, iAlto = 0;
    cin >> iAlto >> iAncho;

    vector< vector<char> > vPlano;
    while( iAncho != 0 && iAlto != 0 ) {

        for( int i = 0; i < iAlto; i++) {
            vector<char> vLinea;
            char c;

            for( int j = 0; j < iAncho; j++) {
                cin >> c;
                vLinea.push_back( c );
            }

            vPlano.push_back( vLinea );
        }

        bool bError = false;
        int i = 0, j = 0;
        while( j < iAncho ) {
            bError = false;

            for( i = iAlto-1; i >= 0; i-- ) {
                if( vPlano[i][j] == 'X' )
                    bError = true;
            }
            if( bError == true ) {
                j++;
            } else {
                int k = 0;
                for( k = j; k < iAncho; k++ ) {
                    if( vPlano[0][k] == 'X' )
                        bError = true;
                }
                if( bError == true ) {
                    j++;
                } else {
                    cout << "bufff" << endl;
                    j = iAncho;
                }
            }

        }
        if( bError == true )
            cout << "ui ui ui" << endl;

        cin >> iAlto >> iAncho;
        vPlano.clear();
    }

    return 0;
}
