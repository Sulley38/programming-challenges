#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<char> > Map;
int Pasos = 0;
bool Fin = false;

Map Inundar( const Map& Orig, const int& Alt, const int& Anch ) {
    Map Res = Orig;
    for( int i = 1; i < Alt+1; i++ ) {
        for( int j = 1; j < Anch+1; j++ ) {
            if( Orig[i][j] == '*' ) {
                if( Orig[i-1][j] == '.' ) Res[i-1][j] = '*';
                if( Orig[i+1][j] == '.' ) Res[i+1][j] = '*';
                if( Orig[i][j-1] == '.' ) Res[i][j-1] = '*';
                if( Orig[i][j+1] == '.' ) Res[i][j+1] = '*';
            }
        }
    }
    return Res;
}

Map Avanzar( const Map& Orig, const int& Alt, const int& Anch ) {
    Map Res = Orig;
    bool Bloqueado = true;
    for( int i = 1; i < Alt+1; i++ ) {
        for( int j = 1; j < Anch+1; j++ ) {
            if( Orig[i][j] == 'S' ) {
                if( Orig[i-1][j] == '.' ) {
                    Res[i-1][j] = 'S'; Bloqueado = false;
                } else if( Orig[i-1][j] == 'D' ) { Bloqueado = false; Fin = true; }
                if( Orig[i+1][j] == '.' ) {
                    Res[i+1][j] = 'S'; Bloqueado = false;
                } else if( Orig[i+1][j] == 'D' ) { Bloqueado = false; Fin = true; }
                if( Orig[i][j-1] == '.' ) {
                    Res[i][j-1] = 'S'; Bloqueado = false;
                } else if( Orig[i][j-1] == 'D' ) { Bloqueado = false; Fin = true; }
                if( Orig[i][j+1] == '.' ) {
                    Res[i][j+1] = 'S'; Bloqueado = false;
                } else if( Orig[i][j+1] == 'D' ) { Bloqueado = false; Fin = true; }
            }
        }
    }
    Pasos++;
    if( Bloqueado ) { Pasos = -1; Fin = true; }
    return Res;
}

int main()
{
    int alto, ancho;
    cin >> alto >> ancho;

    Map Mapa( alto+2, vector<char>(ancho+2) );
    for( int i = 1; i < alto+1; i++ )
        for( int j = 1; j < ancho+1; j++ )
            cin >> Mapa[i][j];

    while( !Fin ) {
        Mapa = Inundar(Mapa, alto, ancho);
        Mapa = Avanzar(Mapa, alto, ancho);
    }

    if( Pasos == -1 ) cout << "KAKTUS" << endl;
    else cout << Pasos << endl;

    return 0;
}
