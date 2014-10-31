#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

string GetBinary( const string& input ) {
    // Comprueba si el numero es binario
    bool Binario = true;
    int tam = input.size();
    if( tam != 10 ) Binario = false;
    for( int i = 0; i < int(input.size()); i++ ) {
        if( input[i] != '0' && input[i] != '1' ) Binario = false;
    }
    if( Binario ) return input;
    // Si es decimal, lo convierte
    int Numero, digito;
    istringstream iss( input );
    iss >> Numero;
    string res;
    while( Numero > 0 ) {
        digito = Numero % 2;
        res.push_back( digito + '0' );
        Numero = ( Numero - digito ) / 2;
    }
    return string( res.rbegin(), res.rend() );
}

int main()
{
    int casos;
    cin >> casos;
    while( casos-- ) {
        string lectura;
        cin >> lectura;
        string numero = GetBinary( lectura );
        double n = numero.size(), x = n-1;
        while( x >= 0 && numero[x] != '1' ) x--;
        x = n - x;
        double M = 90 - 180*(x-1)/(n-1);
        if( M > 0.0 ) M = floor( M );
        else M = ceil( M );
        cout << M << endl;
    }

    return 0;
}
