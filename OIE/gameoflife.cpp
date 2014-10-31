#include <iostream>
#include <vector>

using namespace std;
int CheckCasillas( const vector< vector<char> >& Tablero, int X, int Y );

int CheckCasillas( const vector< vector<char> >& Tablero, int X, int Y )
{
    int iAlrededor = 0;
    if( Tablero[X-1][Y-1] == '*' )
        iAlrededor++;
    if( Tablero[X-1][Y] == '*' )
        iAlrededor++;
    if( Tablero[X-1][Y+1] == '*' )
        iAlrededor++;
    if( Tablero[X][Y+1] == '*' )
        iAlrededor++;
    if( Tablero[X][Y-1] == '*' )
        iAlrededor++;
    if( Tablero[X+1][Y-1] == '*' )
        iAlrededor++;
    if( Tablero[X+1][Y] == '*' )
        iAlrededor++;
    if( Tablero[X+1][Y+1] == '*' )
        iAlrededor++;
    return iAlrededor;
}

int main()
{
    int iAncho = 0, iAlto = 0, iTurnos = 0;
    cin >> iAlto >> iAncho >> iTurnos;

    vector< vector<char> > vTablero( iAlto+2, vector<char>( iAncho+2 ) );
    vector< vector<char> > vTablero2( iAlto+2, vector<char>( iAncho+2 ) );

    // leer tablero
    for( int i = 1; i < iAlto+1; i++ ) {
        for( int j = 1; j < iAncho+1; j++ ) {
            cin >> vTablero[i][j];
        }
    }
    vTablero2 = vTablero;

    // simular
    while( iTurnos-- ) {
        for( int i = 1; i < iAlto+1; i++ ) {
            for( int j = 1; j < iAncho+1; j++ ) {
                if( vTablero[i][j] == '.' ) {
                    if( CheckCasillas( vTablero, i, j ) == 3 ) {
                        vTablero2[i][j] = '*';
                    }
                } else {
                    if( CheckCasillas( vTablero, i, j ) != 2 and CheckCasillas( vTablero, i, j ) != 3 ) {
                        vTablero2[i][j] = '.';
                    }
                }
            }
        }
        vTablero = vTablero2;
    }

    // escribir tablero
    for( int i = 1; i < iAlto+1; i++ ) {
        for( int j = 1; j < iAncho+1; j++ ) {
            cout << vTablero[i][j];
        }
        cout << endl;
    }

    return 0;
}
