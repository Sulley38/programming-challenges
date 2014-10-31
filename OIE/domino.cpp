#include <iostream>

using namespace std;

int main()
{
    int iPartidas = 0;
    cin >> iPartidas;

    string Palabra;
    for( int i = 0; i < iPartidas; i++ ) {
        int iGanador = 0;
        cin >> Palabra;
        char last = Palabra[Palabra.length()-1];

        for( int j = 1; j < 10; j++ ) {
            cin >> Palabra;
            if( Palabra[0] == last ) {
                last = Palabra[Palabra.length()-1];
            } else {
                iGanador = ( j % 2 )+1;
                cin.ignore( 128, '\n' );
                j = 11;
            }
        }

        if( iGanador == 1 )
            cout << "B" << endl;
        else if( iGanador == 2 )
            cout << "A" << endl;
        else
            cout << "E" << endl;
        }

    return 0;
}
