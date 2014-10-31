#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Calcula todas las respuestas (Numeros de Catalan generalizados)
    vector< vector<int> > Res( 26, vector<int>(26) ); // Longitud, variables
    // Inicia las tres primeras filas
    for( int i = 1; i <= 5; i += 2 )
        for( int j = 1; j <= 25; j++ )
            Res[i][j] = j;
    // Calcula, columna a columna
    for( int j = 1; j <= 25; j++ )
        for( int i = 7; i <= 25; i += 2 ) {
            int Suma = Res[i-2][j];
            for( int k = 1; k <= i-6; k += 2 )
                Suma += Res[k][j]*Res[i-5-k][j];
            Res[i][j] = Suma;
        }
    // Contesta
    int n, m;
    while( cin >> n >> m ) cout << Res[n][m] << endl;
    return 0;
}
