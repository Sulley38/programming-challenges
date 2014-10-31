#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

int main()
{
    int Ancho, Alto;
    cin >> Alto;
    while( cin >> Ancho ) {
        queue<PII> Cola;
        vector< vector<int> > Tiempos( Alto, vector<int>(Ancho,-1) );
        vector< vector<char> > Pista( Alto, vector<char>(Ancho) );
        for( int i = 0; i < Alto; ++i )
            for( int j = 0; j < Ancho; ++j ) {
                cin >> Pista[i][j];
                if( Pista[i][j] == 'V' ) {
                    Cola.push( PII(i,j) );
                    Tiempos[i][j] = 0;
                } else if( Pista[i][j] == '#' ) {
                    Tiempos[i][j] = -2;
                }
            }

        int Tmp;
        while( !Cola.empty() ) {
            PII P = Cola.front();
            Cola.pop();
            Tmp = Tiempos[P.first][P.second];

            if( P.first-1 >= 0 && Pista[P.first-1][P.second] == '.' && Tiempos[P.first-1][P.second] == -1 ) {
                Cola.push( PII(P.first-1, P.second) );
                Tiempos[P.first-1][P.second] = Tmp+1;
            }
            if( P.first+1 < Alto && Pista[P.first+1][P.second] == '.' && Tiempos[P.first+1][P.second] == -1 ) {
                Cola.push( PII(P.first+1, P.second) );
                Tiempos[P.first+1][P.second] = Tmp+1;
            }
            if( P.second-1 >= 0 && Pista[P.first][P.second-1] == '.' && Tiempos[P.first][P.second-1] == -1 ) {
                Cola.push( PII(P.first, P.second-1) );
                Tiempos[P.first][P.second-1] = Tmp+1;
            }
            if( P.second+1 < Ancho && Pista[P.first][P.second+1] == '.' && Tiempos[P.first][P.second+1] == -1 ) {
                Cola.push( PII(P.first, P.second+1) );
                Tiempos[P.first][P.second+1] = Tmp+1;
            }
        }

        for( int i = 0; i < Alto; ++i ) {
            for( int j = 0; j < Ancho; ++j ) {
                if( Tiempos[i][j] == Tmp )
                    Pista[i][j] = 'X';
                cout << Pista[i][j];
            }
            cout << endl;
        }

        if( cin >> Alto )
            cout << "---" << endl;
    }

    return 0;
}
