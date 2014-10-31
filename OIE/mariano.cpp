#include <iostream>
#include <vector>

#define MUCHO 1000000

using namespace std;

int main()
{
    int Alto, Ancho;
    cin >> Ancho >> Alto;
    vector< vector<char> > Nivel( Alto, vector<char>(Ancho) );
    vector< vector<int> > Coste( Alto, vector<int>(Ancho, MUCHO) );
    for( int i = 0; i < Alto; ++i )
        for( int j = 0; j < Ancho; ++j ) {
            cin >> Nivel[i][j];
            if( Nivel[i][j] == 'M' ) Coste[i][j] = 0;
        }

    for( int i = 1; i < Alto; ++i )
        for( int j = 0; j < Ancho; ++j ) {
            if( Nivel[i][j] != '*' ) {
                // Asigna el coste minimo de las tres opciones
                Coste[i][j] = min( Coste[i][j], Coste[i-1][j] );
                if( j > 0 ) Coste[i][j] = min( Coste[i][j], Coste[i-1][j-1]+1 );
                if( j < Ancho-1 ) Coste[i][j] = min( Coste[i][j], Coste[i-1][j+1]+1 );
                // Penalizacion por trampa
                if( Nivel[i][j] == 'T' ) Coste[i][j] += 3;
            }
        }

    int Res = MUCHO;
    for( int i = 0; i < Ancho; ++i )
        Res = min( Res, Coste[Alto-1][i] );
    if( Res == MUCHO ) cout << "IMPOSIBLE" << endl;
    else cout << Res << endl;
    return 0;
}
