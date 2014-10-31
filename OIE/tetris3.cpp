#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<char> > Pieza;
Pieza RotarPieza( const Pieza& pRotame );

Pieza RotarPieza( const Pieza& pRotame )
{
    int Alto = pRotame[0].size(), Ancho = pRotame.size();
    Pieza Rotada( Alto, vector<char>( Ancho ) );

    for( int i = 0; i < Alto; i++ ) {
        for( int j = 0; j < Ancho; j++ ) {
            Rotada[i][j] = pRotame[j][Alto-1-i];
        }
    }

    return Rotada;
}

int main()
{
    int iAlto, iAncho, iRotar;
    while( cin >> iAlto >> iAncho >> iRotar ) {
        Pieza vPieza( iAlto, vector<char>( iAncho ) );
        for( int i = 0; i < iAlto; i++ ) {
            for( int j = 0; j < iAncho; j++ ) {
                cin >> vPieza[i][j];
            }
        }

        iRotar = ((iRotar%4)+4)%4;
        while( iRotar-- ) {
            vPieza = RotarPieza( vPieza );
        }

        for( int i = 0; i < int(vPieza.size()); i++ ) {
            for( int j = 0; j < int(vPieza[0].size()); j++ ) {
                cout << vPieza[i][j];
            }
            cout << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}
