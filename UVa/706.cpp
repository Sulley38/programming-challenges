#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector< vector<char> > > Num(10, vector< vector<char> >( 5, vector<char>(3,' ') ) );
    Num[1][1][2] = '|'; Num[1][3][2] = '|';
    Num[2][0][1] = '-'; Num[2][1][2] = '|'; Num[2][2][1] = '-'; Num[2][3][0] = '|'; Num[2][4][1] = '-';
    Num[3][0][1] = '-'; Num[3][1][2] = '|'; Num[3][2][1] = '-'; Num[3][3][2] = '|'; Num[3][4][1] = '-';
    Num[4][1][0] = '|'; Num[4][1][2] = '|'; Num[4][2][1] = '-'; Num[4][3][2] = '|';
    Num[5][0][1] = '-'; Num[5][1][0] = '|'; Num[5][2][1] = '-'; Num[5][3][2] = '|'; Num[5][4][1] = '-';
    Num[6][0][1] = '-'; Num[6][1][0] = '|'; Num[6][2][1] = '-'; Num[6][3][0] = '|'; Num[6][3][2] = '|'; Num[6][4][1] = '-';
    Num[7][0][1] = '-'; Num[7][1][2] = '|'; Num[7][3][2] = '|';
    Num[8][0][1] = '-'; Num[8][1][0] = '|'; Num[8][1][2] = '|'; Num[8][2][1] = '-'; Num[8][3][0] = '|'; Num[8][3][2] = '|'; Num[8][4][1] = '-';
    Num[9][0][1] = '-'; Num[9][1][0] = '|'; Num[9][1][2] = '|'; Num[9][2][1] = '-'; Num[9][3][2] = '|'; Num[9][4][1] = '-';
    Num[0][0][1] = '-'; Num[0][1][0] = '|'; Num[0][1][2] = '|'; Num[0][3][0] = '|'; Num[0][3][2] = '|'; Num[0][4][1] = '-';
    int Tam, Digitos, Alto, Ancho;
    string Numero;
    while( cin >> Tam >> Numero && ( Tam != 0 || Numero != "0" ) ) {
        Digitos = Numero.size();
        Alto = 2*Tam+3;
        Ancho = Digitos*(Tam+2) + Digitos - 1;
        vector< vector<char> > Res( Alto, vector<char>(Ancho,' ') ); // Panel final
        // Construir cada digito
        for( int a = 0; a < Digitos; ++a ) {
            int Current = Numero[a] - '0', X = a*(Tam+2) + a, Y = 0; // Posiciones iniciales
            for( int b = 0; b < 5; ++b ) { // Linea por linea
                if( b % 2 == 0 ) { // Primera, tercera o quinta linea
                    Res[Y][X] = Num[Current][b][0];
                    for( int i = X+1; i < X+Tam+1; ++i )
                        Res[Y][i] = Num[Current][b][1];
                    Res[Y][X+Tam+1] = Num[Current][b][2];
                    Y++;
                } else { // Segunda o cuarta linea y repeticiones
                    for( int r = 0; r < Tam; r++ ) {
                        Res[Y][X] = Num[Current][b][0];
                        for( int i = X+1; i < X+Tam+1; ++i )
                            Res[Y][i] = Num[Current][b][1];
                        Res[Y][X+Tam+1] = Num[Current][b][2];
                        Y++;
                    }
                }
            }
        }
        // Mostrar en pantalla
        for( int i = 0; i < Alto; ++i ) {
            for( int j = 0; j < Ancho; ++j )
                cout << Res[i][j];
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
