#include <iostream>
#include <vector>
#include <string>

using namespace std;
void ProcesarOrden( vector<string>& Pantalla, int& CurX, int& CurY, const string& Orden, const int& X, const int& Y );

void ProcesarOrden( vector<string>& Pantalla, int& CurX, int& CurY, const string& Orden, const int& X, const int& Y, int& Relleno )
{
    if( Orden == "MOV" ){
        CurX = X;
        CurY = 9-Y;
    } else if( Orden == "MOVREL" ){
        CurX += X;
        CurY -= Y;
    } else {
        Relleno++;
        for( int i = CurY; i < CurY+Y; i++ ) {
            if( i >= 0 && i <= 9 ) { // Solo si esta dentro de los margenes
                for( int j = CurX; j < CurX+X; j++ ) {
                    if( j >= 0 && j <= 39 ) { // Solo si esta dentro de los margenes
                        if( i == CurY ) { // Primera linea
                            if( j == CurX || j == CurX+X-1 )
                                Pantalla[i][j] = '#';
                            else
                                Pantalla[i][j] = '=';
                        } else if( i == CurY+Y-1 ) { // Ultima linea
                            if( j == CurX || j == CurX+X-1 )
                                Pantalla[i][j] = '#';
                            else
                                Pantalla[i][j] = '-';
                        } else { // Resto de lineas
                            if( j == CurX || j == CurX+X-1 )
                                Pantalla[i][j] = '!';
                            else
                                Pantalla[i][j] = ( Relleno % 10 ) + '0';
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int iCasos = 0;
    cin >> iCasos;

    vector< vector<string> > vResultado;
    for( int a = 0; a < iCasos; a++ ) {
        int iOrdenes = 0, X = 0, Y = 0, CursorX = 0, CursorY = 0, iNumVentana = 0;
        string sOrden;
        vector<string> vPantalla( 10, "........................................" );

        cin >> iOrdenes;
        for( int b = 0; b < iOrdenes; b++ ) {
            cin >> sOrden >> X >> Y;
            ProcesarOrden( vPantalla, CursorX, CursorY, sOrden, X, Y, iNumVentana );
        }

        vResultado.push_back( vPantalla );
    }

    for( int a = 0; a < iCasos; a++ ) {
        for( int c = 0; c < 10; c++ ) {
            cout << vResultado[a][c] << endl;
        }
        if( a+1 < iCasos )
            cout << "," << endl;
    }

    return 0;
}
