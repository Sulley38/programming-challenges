#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<char> > Tablero;

int GetMaximo( Tablero Tab )
{
    int Maximo = 0, Alto = Tab.size(), Ancho = Tab[0].size();
    // Comprobar horizontalmente
    for( int i = 0; i < Alto; i++ ) {
        int Suma = 0;
        for( int j = 0; j < Ancho; j++ ) {
            if( Tab[i][j] == 'x' ) {
                Suma++;
                if( j + 1 == Ancho )
                    if( Suma > Maximo )
                        Maximo = Suma;
            } else {
                if( Suma > Maximo )
                    Maximo = Suma;
                Suma = 0;
            }
        }
    }
    // Comprobar verticalmente
    for( int i = 0; i < Ancho; i++ ) {
        int Suma = 0;
        for( int j = 0; j < Alto; j++ ) {
            if( Tab[j][i] == 'x' ) {
                Suma++;
                if( j + 1 == Alto )
                    if( Suma > Maximo )
                        Maximo = Suma;
            } else {
                if( Suma > Maximo )
                    Maximo = Suma;
                Suma = 0;
            }
        }
    }

    return Maximo;
}

int main()
{
    int iFilas, iColumnas;
    while( cin >> iFilas >> iColumnas ) {
        Tablero A( iFilas, vector<char>( iColumnas ) );
        for( int i = 0; i < iFilas; i++ ) {
            for( int j = 0; j < iColumnas; j++ ) {
                cin >> A[i][j];
            }
        }

        int iMayor = GetMaximo( A );
        cout << iMayor << endl;
    }

}
