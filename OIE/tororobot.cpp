#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Alto, Ancho, Rango;
    cin >> Ancho >> Alto >> Rango;
    vector< vector<int> > Imagen( Alto, vector<int>(Ancho) ), Suma( Alto, vector<int>(Ancho) );
    for( int i = 0; i < Alto; ++i )
        for( int j = 0; j < Ancho; ++j )
            cin >> Imagen[i][j];
    // Suma del rectangulo entre (0,0) y (i,j)
    Suma[0][0] = Imagen[0][0];
    for( int i = 1; i < Ancho; ++i ) Suma[0][i] = Imagen[0][i] + Suma[0][i-1];
    for( int i = 1; i < Alto; ++i ) Suma[i][0] = Imagen[i][0] + Suma[i-1][0];
    for( int i = 1; i < Alto; ++i )
        for( int j = 1; j < Ancho; ++j )
            Suma[i][j] = Imagen[i][j] + Suma[i-1][j] + Suma[i][j-1] - Suma[i-1][j-1];

    int X = 0, Y = 0, Best = 0;
    // Comprobar todos los resultados posibles
    for( int i = Rango-1; i < Alto; ++i )
        for( int j = Rango-1; j < Ancho; ++j ) {
            int Media = Suma[i][j];
            if( i-Rango >= 0 ) Media -= Suma[i-Rango][j];
            if( j-Rango >= 0 ) {
                Media -= Suma[i][j-Rango];
                if( i-Rango >= 0 ) Media += Suma[i-Rango][j-Rango];
            }
            if( Media > Best ) {
                Best = Media;
                Y = i-Rango+1;
                X = j-Rango+1;
            }
        }

    cout << Y << " " << X << endl;
    return 0;
}
