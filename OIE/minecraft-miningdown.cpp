#include <iostream>
#include <vector>

using namespace std;

int Valor( const char& c ) {
    if( c == 'C' ) return 1;
    else if( c == 'H' ) return 4;
    else if( c == 'R' ) return 8;
    else if( c == 'O' ) return 13;
    else if( c == 'D' ) return 20;
    else return 0;
}

int Cuenta( const vector<char>& Fila, const int& Pos, const int& RL, const int& Ancho )
{
    int Res = 0, Comienzo = Pos-RL, Final = Pos+RL;
    if( Comienzo < 0 ) Comienzo = 0;
    if( Final >= Ancho ) Final = Ancho-1;
    for( int n = Comienzo; n <= Final; n++ )
        Res += Valor(Fila[n]);
    return Res;
}

int Maximo( const vector<int>& Fila, const int& Pos, const int& RL, const int& Ancho )
{
    int Res = 0, Comienzo = Pos-RL, Final = Pos+RL;
    if( Comienzo < 0 ) Comienzo = 0;
    if( Final >= Ancho ) Final = Ancho-1;
    for( int n = Comienzo; n <= Final; n++ )
        Res = max( Res, Fila[n] );
    return Res;
}

int main()
{
    int Casos;
    cin >> Casos;
    for( int a = 0; a < Casos; ++a ) {
        // Leer la entrada
        int Alto, Ancho, Rango;
        cin >> Alto >> Ancho >> Rango;
        int RangoLateral = Rango / 2;
        vector< vector<char> > Mapa( Alto, vector<char>(Ancho) );
        for( int i = 0; i < Alto; ++i )
            for( int j = 0; j < Ancho; ++j )
                cin >> Mapa[i][j];
        // Calcular beneficio maximo
        vector< vector<int> > Beneficio( Alto, vector<int>(Ancho) );
        // Primera fila
        for( int j = 0; j < Ancho; ++j )
            Beneficio[0][j] = Cuenta(Mapa[0],j,RangoLateral,Ancho);
        // Resto de filas
        int Anterior;
        for( int i = 1; i < Alto; ++i ) {
            for( int j = 0; j < Ancho; ++j ) {
                Anterior = Maximo( Beneficio[i-1], j, RangoLateral, Ancho );
                Beneficio[i][j] = Anterior+Cuenta( Mapa[i], j, RangoLateral, Ancho );
            }
        }
        // Determina el maximo y lo muestra
        int Res = Beneficio[Alto-1][0];
        for( int j = 1; j < Ancho; ++j )
            Res = max( Res, Beneficio[Alto-1][j] );
        cout << "Case #" << a+1 << ": " << Res << endl;
    }
    return 0;
}
