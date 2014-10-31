#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Alto, Ancho;
    cin >> Alto >> Ancho;
    vector< vector<char> > Carta( Alto*2, vector<char>(Ancho*2) );

    for( int i = 0; i < Alto; ++i )
        for( int j = 0; j < Ancho; ++j )
            cin >> Carta[i][j];

    int EX, EY;
    cin >> EY >> EX;

    for( int i = 0; i < Alto; ++i ) {
        for( int j = 0; j < Ancho; ++j )
            Carta[i][Ancho+j] = Carta[i][Ancho-1-j];
    }
    for( int i = 0; i < Alto; ++i )
        for( int j = 0; j < Ancho*2; ++j )
            Carta[Alto+i][j] = Carta[Alto-1-i][j];

    if( Carta[EY-1][EX-1] == '.' )
        Carta[EY-1][EX-1] = '#';
    else
        Carta[EY-1][EX-1] = '.';

    for( int i = 0; i < Alto*2; ++i ) {
        for( int j = 0; j < Ancho*2; ++j )
            cout << Carta[i][j];
        cout << endl;
    }

    return 0;
}
