#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Ancho, Alto, Monedas, Escaleras, X, Y;
    cin >> Ancho >> Alto >> Monedas >> Escaleras;
    // Situar los objetos en la pantalla
    vector< vector<char> > Pantalla( Alto, vector<char>(Ancho+1) );
    for( int i = 0; i < Monedas; ++i ) {
        cin >> X >> Y;
        Pantalla[Alto-Y-1][X] = 'c';
    }
    for( int i = 0; i < Escaleras; ++i ) {
        cin >> X >> Y;
        Pantalla[Alto-Y-1][X] = '#';
    }
    // Pasa por todas las casillas contando la recaudacion
    vector< vector<int> > Recaudacion( Alto, vector<int>(Ancho+1,-1) );
    int Colecta = 0;
    // Primera linea
    for( int j = 0; j <= Ancho; ++j ) {
        if( Pantalla[0][j] == 'c' ) Colecta++;
        Recaudacion[0][j] = Colecta;
    }
    // Resto de lineas
    for( int i = 1; i < Alto; ++i ) {
        Colecta = -1;
         // Hasta encontrar la primera escalera valida, no se cuentan las monedas
        for( int j = 0; j <= Ancho; ++j ) {
            if( Pantalla[i][j] == '#' ) {
                if( Recaudacion[i-1][j] > Colecta ) {
                    Colecta = Recaudacion[i-1][j]; // Si por abajo hay menos que por arriba, bajar
                } else if( Colecta > Recaudacion[i-1][j] ) {
                    i--; // Si por arriba hay menos que por abajo, subir
                }
            } else if( Pantalla[i][j] == 'c' && Colecta >= 0 ) {
                Colecta++;
            }
            Recaudacion[i][j] = Colecta;
        }
    }
    cout << Recaudacion[Alto-1][Ancho] << endl;
    return 0;
}
