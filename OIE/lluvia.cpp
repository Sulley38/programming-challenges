#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

int main()
{
    int Alto, Ancho;
    cin >> Alto >> Ancho;
    vector< vector<int> > Mapa( Alto, vector<int>(Ancho) ), Aguas( Alto, vector<int>(Ancho,1) );
    vector< vector<PII> > Conexiones( Alto, vector<PII>(Ancho,PII(-1,-1)) );
    for( int i = 0; i < Alto; ++i )
        for( int j = 0; j < Ancho; ++j )
            cin >> Mapa[i][j];

    for( int i = 0; i < Alto; ++i ) {
        for( int j = 0; j < Ancho; ++j ) {
            PII P(-1,-1);
            int Minimo = Mapa[i][j];
            if( i-1 >= 0 && j-1 >= 0 && Mapa[i-1][j-1] < Minimo ) { Minimo = Mapa[i-1][j-1]; P.second = j-1; P.first = i-1; }
            if( i-1 >= 0 && Mapa[i-1][j] < Minimo ) { Minimo = Mapa[i-1][j]; P.second = j; P.first = i-1; }
            if( i-1 >= 0 && j+1 < Ancho && Mapa[i-1][j+1] < Minimo ) { Minimo = Mapa[i-1][j+1]; P.second = j+1; P.first = i-1; }
            if( j-1 >= 0 && Mapa[i][j-1] < Minimo ) { Minimo = Mapa[i][j-1]; P.second = j-1; P.first = i; }
            if( j+1 < Ancho && Mapa[i][j+1] < Minimo ) { Minimo = Mapa[i][j+1]; P.second = j+1; P.first = i; }
            if( i+1 < Alto && j-1 >= 0 && Mapa[i+1][j-1] < Minimo ) { Minimo = Mapa[i+1][j-1]; P.second = j-1; P.first = i+1; }
            if( i+1 < Alto && Mapa[i+1][j] < Minimo ) { Minimo = Mapa[i+1][j]; P.second = j; P.first = i+1; }
            if( i+1 < Alto && j+1 < Ancho && Mapa[i+1][j+1] < Minimo ) { Minimo = Mapa[i+1][j+1]; P.second = j+1; P.first = i+1; }
            Conexiones[i][j] = P;
        }
    }

    for( int i = 0; i < Alto; ++i ) {
        for( int j = 0; j < Ancho; ++j ) {
            PII P = Conexiones[i][j];
            while( P.first != -1 || P.first != -1 ) {
                Aguas[P.first][P.second]++;
                P = Conexiones[P.first][P.second];
            }
        }
    }

    for( int i = 0; i < Alto; ++i ) {
        for( int j = 0; j < Ancho-1; ++j )
            cout << Aguas[i][j] << " ";
        cout << Aguas[i][Ancho-1] << endl;
    }

    return 0;
}
