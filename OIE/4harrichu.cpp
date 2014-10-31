#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> Pos; // Y, X

int main()
{
    int N; cin >> N;
    while( N-- ) {
        // Lee los datos de la entrada
        int Alto, Ancho;
        cin >> Alto >> Ancho;
        vector< vector<char> > Laberinto( Alto, vector<char>(Ancho) );
        Pos Inicial;
        for( int i = 0; i < Alto; ++i ) {
            for( int j = 0; j < Ancho; ++j ) {
                cin >> Laberinto[i][j];
                if( Laberinto[i][j] == 'b' ) {
                    Inicial.first = i; Inicial.second = j;
                }
            }
        }
        // BFS
        bool Terminar = false;
        queue<Pos> Cola;
        Cola.push(Inicial);
        while( !Cola.empty() && !Terminar ) {
            Pos Current = Cola.front();
            Laberinto[Current.first][Current.second] = '#'; // No volvemos a pasar por aqui
            Cola.pop();
            // Explora las posibilidades
            if( Current.first-1 >= 0 && Laberinto[Current.first-1][Current.second] == '.' )
                Cola.push( Pos(Current.first-1, Current.second) );
            else if( Current.first-1 >= 0 && Laberinto[Current.first-1][Current.second] == 'g' )
                Terminar = true;
            if( Current.first+1 < Alto && Laberinto[Current.first+1][Current.second] == '.' )
                Cola.push( Pos(Current.first+1, Current.second) );
            else if( Current.first+1 < Alto && Laberinto[Current.first+1][Current.second] == 'g' )
                Terminar = true;
            if( Current.second-1 >= 0 && Laberinto[Current.first][Current.second-1] == '.' )
                Cola.push( Pos(Current.first, Current.second-1) );
            else if( Current.second-1 >= 0 && Laberinto[Current.first][Current.second-1] == 'g' )
                Terminar = true;
            if( Current.second+1 < Ancho && Laberinto[Current.first][Current.second+1] == '.' )
                Cola.push( Pos(Current.first, Current.second+1) );
            else if( Current.second+1 < Ancho && Laberinto[Current.first][Current.second+1] == 'g' )
                Terminar = true;
        }
        if( Terminar ) cout << "Good" << endl;
        else cout << "Bad" << endl;
    }
    return 0;
}
