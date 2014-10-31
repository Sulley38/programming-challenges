#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = 0;
    bool Add1 = true;
    string Termino, Salida;

    while( cin >> Termino ) {
        // Signo
        if( Termino[i] == '-' ) {
            Salida.push_back( '-' );
            i++;
        }
        else if( Termino[i] == '+' ) {
            i++;
        }
        // Números
        while( Termino[i] >= '0' && Termino[i] <= '9' ) {
            Salida.push_back( Termino[i] );
            Add1 = false;
            i++;
        }
        if( Add1 ) {
            Salida.push_back( '1' );
        }
        // Punto
        Salida.push_back( '.' );
        // Letra
        while( Termino[i] >= 'a' && Termino[i] <= 'z' ) {
            Salida.push_back( Termino[i] );
            i++;
        }

        cout << Salida << endl;
        Salida.clear();
        Termino.clear();
        i = 0;
        Add1 = true;
    }

    return 0;
}
