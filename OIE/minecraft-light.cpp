#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Data {
    int X, Y, Nivel;
};

int main()
{
    int Alto, Ancho, Ilum;
    cin >> Alto >> Ancho >> Ilum;
    vector< vector<char> > Mundo( Alto, vector<char>(Ancho) );
    vector< vector<int> > NivelI( Alto, vector<int>(Ancho) );
    // Leer el mundo
    queue<Data> Cola;
    Data A; A.Nivel = 15;
    for( int i = 0; i < Alto; ++i ) {
        for( int j = 0; j < Ancho; ++j ) {
            cin >> Mundo[i][j];
            A.X = j;
            A.Y = i;
            if( Mundo[i][j] == 'X' )
                NivelI[i][j] = 16; // Bloque opaco
            else if( Mundo[i][j] == 'A' )
                Cola.push(A);
        }
    }
    // Iluminacion solar
    A.Nivel = Ilum;
    for( int j = 0; j < Ancho; ++j ) {
        A.X = j;
        for( int i = 0; i < Alto; ++i ) {
            A.Y = i;
            if( Mundo[i][j] != 'X' )
                Cola.push(A);
            else
                i = Alto;
        }
    }
    // Expandir la luz
    while( !Cola.empty() ) {
        A = Cola.front();
        Cola.pop();
        if( NivelI[A.Y][A.X] < A.Nivel )
            NivelI[A.Y][A.X] = A.Nivel;
        // Propagar a las casillas adyacentes
        if( A.Y > 0 && NivelI[A.Y-1][A.X] < A.Nivel-1 ) {
            A.Y--;
            A.Nivel--;
            Cola.push(A);
            A.Y++;
            A.Nivel++;
        }
        if( A.Y < Alto-1 && NivelI[A.Y+1][A.X] < A.Nivel-1 ) {
            A.Y++;
            A.Nivel--;
            Cola.push(A);
            A.Y--;
            A.Nivel++;
        }
        if( A.X > 0 && NivelI[A.Y][A.X-1] < A.Nivel-1 ) {
            A.X--;
            A.Nivel--;
            Cola.push(A);
            A.X++;
            A.Nivel++;
        }
        if( A.X < Ancho-1 && NivelI[A.Y][A.X+1] < A.Nivel-1 ) {
            A.X++;
            A.Nivel--;
            Cola.push(A);
            A.X--;
            A.Nivel++;
        }
    }
    // Mostrar el resultado
    for( int i = 0; i < Alto; ++i ) {
        for( int j = 0; j < Ancho; ++j ) {
            if( NivelI[i][j] <= 7 )
                Mundo[i][j] = 'M';
            cout << Mundo[i][j];
        }
        cout << endl;
    }
}
