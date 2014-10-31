#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void Print( const vector< vector<char> >& T ) {
    for( int i = 0; i < 6; i++ ) {
        cout << "|";
        for( int j = 0; j < 8; j++ ) {
            if( T[i][j] != 0 ) cout << T[i][j];
            else cout << " ";
        }
        cout << "|" << endl;
    }
    cout << "\\--------/" << endl;
}

int Comprobar( const vector< vector<char> >& T, const int& F, const int& C, const char& P ) {
    // Comprueba CONNECT4
    int Sec = 1, i = F+1, j = C;
    // Vertical
    while( i < 6 && T[i][j] == P ) { Sec++; i++; }
    if( Sec >= 4 ) return 2;
    // Horizonal
    Sec = 1; i = F; j = C+1;
    while( j < 8 && T[i][j] == P ) { Sec++; j++; }
    j = C-1;
    while( j >= 0 && T[i][j] == P ) { Sec++; j--; }
    if( Sec >= 4 ) return 2;
    // Diagonal 1
    Sec = 1; i = F-1; j = C-1;
    while( i >= 0 && j >= 0 && T[i][j] == P ) { Sec++; i--; j--; }
    i = F+1; j = C+1;
    while( i < 6 && j < 8 && T[i][j] == P ) { Sec++; i++; j++; }
    if( Sec >= 4 ) return 2;
    // Diagonal 2
    Sec = 1; i = F-1; j = C+1;
    while( i >= 0 && j < 8 && T[i][j] == P ) { Sec++; i--; j++; }
    i = F+1; j = C-1;
    while( i < 6 && j >= 0 && T[i][j] == P ) { Sec++; i++; j--; }
    if( Sec >= 4 ) return 2;

    // Comprueba FULL
    if( F == 0 ) {
        bool Full = true;
        for( int a = 0; a < 8; a++ ) if( T[0][a] == 0 ) Full = false;
        if( Full ) return 1;
    }

    return 0;
}

int main()
{
    vector< vector<char> > Tablero( 6, vector<char>(8) );
    int n = 0, Turno = 0;
    string s;
    while( getline( cin, s ) ) {
        if( s == "" ) {
            Print( Tablero );
        } else {
            istringstream iss( s );
            while( iss >> n ) {
                if( Tablero[0][n-1] != 0 ) {
                    cout << "INVALID" << endl;
                } else {
                    // Mete la ficha en su lugar
                    int p = 5;
                    while( Tablero[p][n-1] != 0 ) p--;
                    Tablero[p][n-1] = Turno + '0';
                    // Comprueba si hay CONNECT4 o FULL
                    int r = Comprobar( Tablero, p, n-1, Turno + '0' );
                    if( r == 1 ) {
                        cout << "FULL" << endl;
                        Print( Tablero );
                        return 0;
                    } else if( r == 2 ) {
                        cout << "CONNECT4" << endl;
                        Print( Tablero );
                        return 0;
                    } else {
                       Turno = !Turno;
                    }
                }
            }
        }
    }

    cout << "QUIT" << endl;

    return 0;
}
