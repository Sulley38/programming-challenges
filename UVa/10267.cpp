#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

int main()
{
    char c;
    int Alto, Ancho;
    vector< vector<char> > Imagen;
    while( cin >> c && c != 'X' ) {
        if( c == 'I' ) {
            // Nueva tabla
            Imagen.clear();
            cin >> Ancho >> Alto;
            Imagen.resize( Alto, vector<char>(Ancho,'O') );
        } else if( c == 'C' ) {
            // Limpiar
            Imagen.clear();
            Imagen.resize( Alto, vector<char>(Ancho,'O') );
        } else if( c == 'L' ) {
            // Pixel en concreto
            int X, Y;
            cin >> X >> Y >> c;
            Imagen[Y-1][X-1] = c;
        } else if( c == 'V' ) {
            // Linea vertical
            int X, Y1, Y2;
            cin >> X >> Y1 >> Y2 >> c;
            for( int i = min(Y1,Y2); i <= max(Y1,Y2); ++i )
                Imagen[i-1][X-1] = c;
        } else if( c == 'H' ) {
            // Linea horizontal
            int X1, X2, Y;
            cin >> X1 >> X2 >> Y >> c;
            for( int i = min(X1,X2); i <= max(X1,X2); ++i )
                Imagen[Y-1][i-1] = c;
        } else if( c == 'K' ) {
            // Rectangulo
            int X1, X2, Y1, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2 >> c;
            for( int i = Y1; i <= Y2; ++i )
                for( int j = X1; j <= X2; ++j )
                    Imagen[i-1][j-1] = c;
        } else if( c == 'F' ) {
            int X, Y;
            cin >> X >> Y >> c;
            char OldPixel = Imagen[Y-1][X-1];
            // Busqueda de pixeles en la region
            if( c != OldPixel ) {
                queue<PII> Region;
                Region.push( PII(X,Y) );
                Imagen[Y-1][X-1] = c;
                while( !Region.empty() ) {
                    PII P = Region.front();
                    Region.pop();
                    if( P.second-2 >= 0 && Imagen[P.second-2][P.first-1] == OldPixel ) {
                        Imagen[P.second-2][P.first-1] = c;
                        Region.push( PII(P.first,P.second-1) );
                    }
                    if( P.second < Alto && Imagen[P.second][P.first-1] == OldPixel ) {
                        Imagen[P.second][P.first-1] = c;
                        Region.push( PII(P.first,P.second+1) );
                    }
                    if( P.first-2 >= 0 && Imagen[P.second-1][P.first-2] == OldPixel ) {
                        Imagen[P.second-1][P.first-2] = c;
                        Region.push( PII(P.first-1,P.second) );
                    }
                    if( P.first < Ancho && Imagen[P.second-1][P.first] == OldPixel ) {
                        Imagen[P.second-1][P.first] = c;
                        Region.push( PII(P.first+1,P.second) );
                    }
                }
            }
        } else if( c == 'S' ) {
            // Muestra en pantalla
            string s;
            cin >> s;
            cout << s << endl;
            for( int i = 0; i < Alto; ++i ) {
                for( int j = 0; j < Ancho; ++j )
                    cout << Imagen[i][j];
                cout << endl;
            }
        }
    }

    return 0;
}
