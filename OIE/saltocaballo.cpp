#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef vector< vector<char> > Tab;
typedef pair<int,int> PII;
int Alto, Ancho, Saltos = 0, Proximo = 0, Restantes = 1;
queue<PII> Cola;

bool Comprobar( Tab& T, const int& i, const int& j )
{
    if( i >= 0 && i < Alto && j >= 0 && j < Ancho) {
        if( T[i][j] == '.' ) {
            Cola.push( PII(i,j) );
            T[i][j] = '#'; // Evita encolar la misma casilla varias veces
            Proximo++;
        } else if( T[i][j] == 'X' ) {
            Restantes = 1;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> Alto >> Ancho;
    Tab Tablero( Alto, vector<char>(Ancho, '#') );
    // Lee la entrada
    PII Inicial;
    for( int i = 0; i < Alto; ++i )
        for( int j = 0; j < Ancho; ++j ) {
            cin >> Tablero[i][j];
            if( Tablero[i][j] == 'C' ) { Inicial.first = i; Inicial.second = j; Tablero[i][j] = '#'; }
        }
    // BFS
    bool Terminar = false;
    Cola.push(Inicial);
    while( !Cola.empty() && !Terminar ) {
        PII C = Cola.front(); Cola.pop();
        // Barajamos 8 movimientos
        if( Comprobar( Tablero, C.first-2, C.second-1 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first-2, C.second+1 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first-1, C.second-2 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first-1, C.second+2 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first+1, C.second-2 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first+1, C.second+2 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first+2, C.second-1 ) ) Terminar = true;
        if( !Terminar && Comprobar( Tablero, C.first+2, C.second+1 ) ) Terminar = true;
        // Contador de saltos
        Restantes--;
        if( Restantes == 0 ) {
            Saltos++;
            Restantes = Proximo;
            Proximo = 0;
        }
    }
    if( Terminar ) cout << Saltos << endl;
    else cout << "-1" << endl;
    return 0;
}


