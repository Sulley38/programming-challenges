#include <iostream>
#include <vector>

using namespace std;

char GetNextChar( const vector< vector<char> >& vHabitacion, int X, int Y, int iDir )
{
    if( iDir == 0 )
        Y--;
    else if( iDir == 1 )
        X++;
    else if( iDir == 2 )
        Y++;
    else if( iDir == 3 )
        X--;

    if( X < int(vHabitacion[0].size()) && X >= 0 && Y < int(vHabitacion.size()) && Y >= 0)
        return vHabitacion[Y][X];
    else
        return '0';
}

int main()
{
    int iAlto = 0, iAncho = 0;
    cin >> iAlto >> iAncho;

    char c;
    vector< vector<char> > vHabitacion( iAlto, vector<char>( iAncho ) );
    for( int i = 0; i < iAlto; i++ ) {
        for( int j = 0; j < iAncho; j++ ) {
            cin >> c;
            vHabitacion[i][j] = c;
        }
    }

    bool bFin = false;
    int X = iAncho/2, Y = iAlto/2, iDir = 0;
    while( !bFin ) {
        vHabitacion[Y][X] = 'V';

        char Next = GetNextChar( vHabitacion, X, Y, iDir );
        if( Next == '*' || Next == 'V' || Next == '0' ) {
            iDir++;
            if( iDir > 3 )
                iDir = 0;
            Next = GetNextChar( vHabitacion, X, Y, iDir );
            if( Next == '*' || Next == 'V' || Next == '0' )
                bFin = true;
        }

        if( iDir == 0 )
            Y--;
        else if( iDir == 1 )
            X++;
        else if( iDir == 2 )
            Y++;
        else if( iDir == 3 )
            X--;
    }

    for( int i = 0; i < iAlto; i++ ) {
        for( int j = 0; j < iAncho; j++ ) {
            cout << vHabitacion[i][j];
        }
        cout << endl;
    }

    return 0;
}
