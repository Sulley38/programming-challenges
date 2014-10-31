#include <iostream>
#include <string>

using namespace std;
string Japonizar( string texto );
string consonantes = "BCDFGHJKLMPQRSTVWXYZbcdfghjklmpqrstvwxyz", vocales = "AEIOUaeiou", n = "nN";

string Japonizar( string texto )
{
    string japonizado = "Konnichi wa, ";

    for( unsigned int j = 0; j < texto.length(); j++ ) {
        if( consonantes.find( texto[j] ) != string::npos && vocales.find( texto[j+1] ) == string::npos && n.find( texto[j] ) == string::npos ) {
            japonizado.push_back( texto[j] );
            japonizado.push_back( 'u' );
        } else {
            japonizado.push_back( texto[j] );
        }
    }
    japonizado.append( "-san" );

    return japonizado;
}

int main()
{
    int iLineas;
    string Entrada, Salida;
    cin >> iLineas;
    cin.ignore();

    for( int i = 0; i < iLineas; i++ ) {
        getline( cin, Entrada );
        Salida = Japonizar( Entrada );
        cout << Salida << endl;
    }

    return 0;
}

