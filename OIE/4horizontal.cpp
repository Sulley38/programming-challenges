#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iAlto = 0, iAncho = 0, iBarras = 0;
    cin >> iAlto >> iAncho;

    vector< vector<char> > vCaracteres( iAlto, vector<char>( iAncho ) );
    for( int i = 0; i < iAlto; i++ ) {
        for( int j = 0; j < iAncho; j++ ) {
            cin >> vCaracteres[i][j];
        }
    }

    for( int i = 0; i < iAlto; i++ ) {
        for( int j = 0; j < iAncho; j++ ) {
            if( vCaracteres[i][j] == '-' && vCaracteres[i][j+1] == '-' ) {
                iBarras++;
                while( vCaracteres[i][j] == '-' ) { j++; }
            }
        }
    }

    cout << iBarras << endl;

    return 0;
}
