#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iPuntos = 0, iLineas = 0, iNivel = 1;
    int Puntuaciones[5] = { 0, 1, 3, 6, 10 };
    string Entrada;
    getline( cin, Entrada );

    for( unsigned int i = 0; i < Entrada.length(); i++ ) {
        iPuntos += Puntuaciones[Entrada[i] - '0'] * iNivel;
        iLineas += Entrada[i] - '0';
        if( iLineas >= 10 ) {
            iLineas -= 10;
            iNivel++;
        }
    }

    cout << iPuntos << endl;
    return 0;
}
