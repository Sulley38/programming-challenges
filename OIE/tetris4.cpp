#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<char> > Espacio;
typedef pair<int,int> Coordenadas;

int Posicionar( const Espacio& Superficie, const vector<Coordenadas>& Ficha, const int X, const int Y );

int Posicionar( const Espacio& Superficie, const vector<Coordenadas>& Ficha, const int X, const int Y )
{
    // 0: ok / 1: !! / 2: desplazar
    int iPosicion = 0, iAncho = Superficie[0].size(), iAlto = Superficie.size(), XCasilla, YCasilla;

    for( int i = 0; i < int(Ficha.size()); i++ ) {
        XCasilla = Ficha[i].first + X;
        YCasilla = Ficha[i].second + Y;

        if( YCasilla < 0 || YCasilla >= iAlto || XCasilla < 0 || XCasilla >= iAncho )
            iPosicion = 2;
        else if( Superficie[YCasilla][XCasilla] == 'X' )
            return 1;
    }

    return iPosicion;
}

int main()
{
    int n, m, N, M;
    cin >> n >> m >> N >> M;

    vector<Coordenadas> Pieza;
    Espacio Tablero( N, vector<char>(M) );
    char c;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            cin >> c;
            if( c == 'X' ) Pieza.push_back( Coordenadas(j,i) );
        }
    }

    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < M; j++ ) {
            cin >> Tablero[i][j];
        }
    }

    int X, Y;
    while( cin >> Y >> X ) {
        Y--; X--;
        int iRes = Posicionar( Tablero, Pieza, X, Y );

        if( iRes == 0 ) {
            cout << "ok" << endl;
        } else if( iRes == 1 ) {
            cout << "!!" << endl;
        } else {
            int iOffset = 0;
            if( X < 0 ) iOffset = max( -m, X );
            else iOffset = min( M, X );

            while( iRes == 2 && ( ( X < 0 && iOffset <= 0 ) || ( X > M - m && iOffset >= M - m ) ) ) {
                iRes = Posicionar( Tablero, Pieza, iOffset, Y );
                if( iRes == 2 ) {
                    if( iOffset <= 0 ) iOffset++;
                    else iOffset--;
                }
            }

            if( iRes == 0 ) {
                if( X < 0 )
                    cout << "+" << iOffset-X << endl;
                else
                    cout << "-" << X-iOffset << endl;
            } else {
                cout << "out" << endl;
            }
        }
    }

    return 0;
}
