#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char,int> Posicion;

Posicion LeerTablero( vector< vector<char> >& Tablero );
bool ComprobarCasilla( const vector< vector<char> >& Tablero, const int& X, const int& Y );
string ComprobarRey( const vector< vector<char> >& Tablero, const Posicion& Rey );

Posicion LeerTablero( vector< vector<char> >& Tablero )
{
    char X, cTipo;
    int Y, iFichas;
    Posicion R;

    cin >> X >> Y;
    Tablero[X-'a'][Y-1] = 'R';
    R.first = X-'a';
    R.second = Y-1;

    cin >> iFichas;
    while( iFichas-- ) {
        cin >> cTipo >> X >> Y;
        Tablero[X-'a'][Y-1] = cTipo;
    }

    return R;
}

bool ComprobarCasilla( const vector< vector<char> >& Tablero, const int& X, const int& Y )
{
    // Check Horizontal/Vetical (T)
    int i = X + 1;
    while( i < 8 ) {
        if( Tablero[i][Y] != '.' && Tablero[i][Y] != 'R' ) {
            if( Tablero[i][Y] == 'T' || Tablero[i][Y] == 'D' )
                return false;
            else
                break;
        }
        i++;
    } i = X - 1;
    while( i >= 0 ) {
        if( Tablero[i][Y] != '.' && Tablero[i][Y] != 'R' ) {
            if( Tablero[i][Y] == 'T' || Tablero[i][Y] == 'D' )
                return false;
            else
                break;
        }
        i--;
    } i = Y + 1;
    while( i < 8 ) {
        if( Tablero[X][i] != '.' && Tablero[X][i] != 'R' ) {
            if( Tablero[X][i] == 'T' || Tablero[X][i] == 'D' )
                return false;
            else
                break;
        }
        i++;
    } i = Y - 1;
    while( i >= 0 ) {
        if( Tablero[X][i] != '.' && Tablero[X][i] != 'R' ) {
            if( Tablero[X][i] == 'T' || Tablero[X][i] == 'D' )
                return false;
            else
                break;
        }
        i--;
    }
    // Check Diagonal (A)
    i = 1;
    while( X+i < 8 && Y+i < 8 ) {
        if( Tablero[X+i][Y+i] != '.' && Tablero[X+i][Y+i] != 'R' ) {
            if( Tablero[X+i][Y+i] == 'A' || Tablero[X+i][Y+i] == 'D' )
                return false;
            else
                break;
        }
        i++;
    } i = 1;
    while( X+i < 8 && Y-i >= 0 ) {
        if( Tablero[X+i][Y-i] != '.' && Tablero[X+i][Y-i] != 'R' ) {
            if( Tablero[X+i][Y-i] == 'A' || Tablero[X+i][Y-i] == 'D' )
                return false;
            else
                break;
        }
        i++;
    } i = 1;
    while( X-i >= 0 && Y+i < 8 ) {
        if( Tablero[X-i][Y+i] != '.' && Tablero[X-i][Y+i] != 'R' ) {
            if( Tablero[X-i][Y+i] == 'A' || Tablero[X-i][Y+i] == 'D' )
                return false;
            else
                break;
        }
        i++;
    } i = 1;
    while( X-i >= 0 && Y-i >= 0 ) {
        if( Tablero[X-i][Y-i] != '.' && Tablero[X-i][Y-i] != 'R' ) {
            if( Tablero[X-i][Y-i] == 'A' || Tablero[X-i][Y-i] == 'D' )
                return false;
            else
                break;
        }
        i++;
    }

    return true;
}

string ComprobarRey( const vector< vector<char> >& Tablero, const Posicion& Rey )
{
    int X = Rey.first-1;
    int Y = Rey.second-1;
    string Res = "";

    for( int i = 0; i <= 2; i++ ) {
        for( int j = 0; j <= 2; j++ ) {
            if( X+i < 8 && X+i >= 0 && Y+j < 8 && Y+j >= 0 && ( i != 1 || j != 1 ) ) {
                if( ComprobarCasilla( Tablero, X+i, Y+j ) ) {
                    Res.push_back( ' ' );
                    Res.push_back( X + i + 'a' );
                    Res.push_back( Y + 1 + j + '0' );
                }
            }
        }
    }

    if( Res == "" ){
        if( ComprobarCasilla( Tablero, Rey.first, Rey.second ) )
            Res.append( " ahogado" );
        else
            Res.append( " mate" );
    }

    return Res;
}

int main()
{
    int iTableroActual = 1, iTableros = 0;
    cin >> iTableros;

    while( iTableros-- ) {
        vector< vector<char> > vTablero( 8, vector<char>(8, '.') );
        Posicion Rey = LeerTablero( vTablero );

        string Resultado;
        Resultado = ComprobarRey( vTablero, Rey );

        cout << "tablero " << iTableroActual << ":" << Resultado << endl;
        iTableroActual++;
    }

    return 0;
}
