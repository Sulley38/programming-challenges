#include <iostream>
#include <vector>

using namespace std;

void Simular( const vector< vector<char> >& Tablero, const int& XS, const int& YS, const char& DirS );

void Simular( const vector< vector<char> >& Tablero, const int& XS, const int& YS, const char& DirS )
{
    string Direccion = "NESO";
    int iDir = Direccion.find( DirS );
    int X = XS, Y = YS;

    bool bTerminar = false;
    while( !bTerminar ) {
        // Girar o explotar
        if( Tablero[Y][X] == 'I' ) {
            iDir--;
            if( iDir < 0 ) iDir = 3;
        } else if( Tablero[Y][X] == 'D' ) {
            iDir++;
            if( iDir > 3 ) iDir = 0;
        } else if( Tablero[Y][X] == 'R' ) {

        } else if( Tablero[Y][X] == 'X' ) {
            cout << "explota" << endl;
            bTerminar = true;
        } else {
            cout << "sale" << endl;
            bTerminar = true;
        }
        // Avanzar
        if( !bTerminar ) {
            if( iDir == 0 )
                Y--;
            else if( iDir == 1 )
                X++;
            else if( iDir == 2 )
                Y++;
            else if( iDir == 3 )
                X--;

            // Comprobar movimiento infinito
            if( X == XS && Y == YS && iDir == int(Direccion.find( DirS )) ){
                cout << "no sale" << endl;
                bTerminar = true;
            }
        }
    }
}

int main()
{
    int iCasos = 0;
    cin >> iCasos;

    for( int a = 0; a < iCasos; a++ ) {

        int iAncho = 0, iAlto = 0;
        cin >> iAlto >> iAncho;
        vector< vector<char> > vTablero( iAlto+2, vector<char>( iAncho+2 ) );

        for( int i = 1; i < iAlto+1; i++ ) {
            for( int j = 1; j< iAncho+1; j++ ) {
                cin >> vTablero[i][j];
            }
        }

        int XStart = 0, YStart = 0;
        char DirStart;
        cin >> YStart >> XStart >> DirStart;

        Simular( vTablero, XStart, YStart, DirStart );
    }

    return 0;
}
