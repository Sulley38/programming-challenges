#include <iostream>

using namespace std;

string Add( const string& Cadena, const int& Numero )
{
    string Res;
    for( int i = 0; i < Numero; i++ )
        Res.push_back( Cadena[Numero-i-1] );

    return Res;
}

bool CompPalindromo( const string& Texto )
{
    int Mitad = Texto.size()/2, Total = Texto.size();
    for( int i = 0; i < Mitad; i++ ) {
        if( Texto[i] != Texto[Total-i-1] ) return false;
    }

    return true;
}

int main()
{
    string Entrada;
    while( cin >> Entrada ) {
        int Letras = 0;
        string Compuesto( Entrada );
        Compuesto.append( Add( Entrada, Letras ) );

        while( !CompPalindromo( Compuesto ) ) {
            Letras++;
            Compuesto = Entrada;
            Compuesto.append( Add( Entrada, Letras ) );
        }

        cout << Compuesto << endl;
    }

    return 0;
}
