#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iAlto, iAncho;
    while( cin >> iAlto >> iAncho ) {
        int iEstrellas = 0;
        vector< vector<char> > vCuadricula( iAlto, vector<char>( iAncho ) );

        for( int i = 0; i < iAlto; i++ ) {
            for( int j = 0; j < iAncho; j++ ) {
                cin >> vCuadricula[i][j];
            }
        }

        for( int i = 1; i < iAlto-1; i++ ) {
            for( int j = 1; j < iAncho-1; j++ ) {
                if( vCuadricula[i][j] == '*' && vCuadricula[i-1][j] == '*' && vCuadricula[i+1][j] == '*' && vCuadricula[i][j-1] == '*' && vCuadricula[i][j+1] == '*' )
                    iEstrellas++;
            }
        }

        cout << iEstrellas << endl;
    }

    return 0;
}
