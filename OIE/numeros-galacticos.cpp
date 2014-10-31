#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string Entrada;

    while( getline( cin, Entrada ) ) {
        unsigned int it = 0;

        while( it < Entrada.size() ) {
            if( Entrada[it] >= '0' && Entrada[it] <= '9' ) {
                string Numero;
                int iNumero = 0, comienzo = 0, length = 0;

                comienzo = it;
                while( Entrada[it] != ' ' && it < Entrada.size() ) { it++; }
                length = it-comienzo;
                Numero.append( Entrada, comienzo, length );

                istringstream iss( Numero );
                iss >> iNumero;
                if( iNumero > 1 ) {
                    cout << iNumero << endl;
                } else {
                    cout << "Supercalifragilisticoespialidoso" << endl;
                }
            }
            it++;
        }

    }

    return 0;
}
