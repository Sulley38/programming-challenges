#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
vector< vector<int> > circulos( 0, vector<int>(0) );
void PintarRecuadro( int X1, int Y1, int X2, int Y2, int nCirculos );
int ComprobarCirculos( const int& X, const int& Y, const int& nCirculos );

void PintarRecuadro( int X1, int Y1, int X2, int Y2, int nCirculos )
{
    int X1inicial = X1;

    while( Y1 >= Y2 ) {
        while( X1 <= X2 ) {
            if ( ComprobarCirculos( X1, Y1, nCirculos ) == 1 ) {
                cout << "#";
            } else {
                if( X1 == 0 && Y1 == 0 )
                    cout << "+";
                else if( X1 == 0 && Y1 != 0 )
                    cout << "|";
                else if( Y1 == 0 && X1 != 0 )
                    cout << "-";
                else
                    cout << ".";
            }
            X1++;
        }
        cout << endl;
        X1 = X1inicial;
        Y1--;
    }
}

int ComprobarCirculos( const int& X, const int& Y, const int& nCirculos )
{
    for ( int i = 0; i < nCirculos; i++ ) {
        double Distancia = sqrt( pow( X - circulos[i][0], 2 ) + pow( Y - circulos[i][1], 2 ) );
        if( ceil( Distancia ) <= circulos[i][2] )
            return 1;
    }
    return 0;
}

int main()
{
    int X1=0, Y1=0, Y1n=0, X2=0, Y2=0, iCirculos=0;
    cin >> X1 >> Y1 >> X2 >> Y2 >> iCirculos;
    circulos.resize( iCirculos );

    for( int i = 0; i < iCirculos; i++ ) {
        circulos[i].resize( 3 );
        cin >> circulos[i][0] >> circulos[i][1] >> circulos[i][2];
    }

    Y1n = Y2; Y2 = Y1; Y1 = Y1n; // Alterna los puntos
    PintarRecuadro( X1, Y1, X2, Y2, iCirculos );

    return 0;
}

