#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PintarPeter( char C, vector<string>& Dibujo ) {
    Dibujo[0].append( ".#.." );
    Dibujo[1].append( "#.#." );
    Dibujo[2].append( "." );
    Dibujo[2].push_back(C);
    Dibujo[2].append( ".#" );
    Dibujo[3].append( "#.#." );
    Dibujo[4].append( ".#.." );
}

void PintarWendy( char C, vector<string>& Dibujo ) {
    Dibujo[0].append( ".*.." );
    Dibujo[1].append( "*.*." );
    Dibujo[2][ int(Dibujo[2].size())-1 ] = '*';
    Dibujo[2].append( "." );
    Dibujo[2].push_back(C);
    Dibujo[2].append( ".*" );
    Dibujo[3].append( "*.*." );
    Dibujo[4].append( ".*.." );
}

int main()
{
    vector<char> Entrada;
    vector<string> Salida( 5 );
    Salida[0] = "."; Salida[1] = "."; Salida[2] = "#"; Salida[3] = "."; Salida[4] = ".";

    char c;
    int letras = 1;
    while( cin >> c ) {
        if( letras % 3 == 0 ) PintarWendy( c, Salida );
        else PintarPeter( c, Salida );
        letras++;
    }

    for( int i = 0; i < 5; i++ ) cout << Salida[i] << endl;

    return 0;
}
