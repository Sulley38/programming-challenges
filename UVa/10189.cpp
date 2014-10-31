#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, Caso = 0;
    while( cin >> n >> m && ( m != 0 || n != 0 ) ) {
        char c;
        vector< vector<char> > Tablero( n, vector<char>(m,'0') );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                cin >> c;
                if( c == '*' ) {
                    Tablero[i][j] = '*';
                    if( i-1 >= 0 && j-1 >= 0 && Tablero[i-1][j-1] != '*' ) Tablero[i-1][j-1]++;
                    if( i-1 >= 0 && Tablero[i-1][j] != '*' )  Tablero[i-1][j]++;
                    if( i-1 >= 0 && j+1 < m && Tablero[i-1][j+1] != '*' ) Tablero[i-1][j+1]++;
                    if( j-1 >= 0 && Tablero[i][j-1] != '*' ) Tablero[i][j-1]++;
                    if( j+1 < m && Tablero[i][j+1] != '*' ) Tablero[i][j+1]++;
                    if( i+1 < n && j-1 >= 0 && Tablero[i+1][j-1] != '*' ) Tablero[i+1][j-1]++;
                    if( i+1 < n && Tablero[i+1][j] != '*' ) Tablero[i+1][j]++;
                    if( i+1 < n && j+1 < m && Tablero[i+1][j+1] != '*' ) Tablero[i+1][j+1]++;
                }
            }
        }

        Caso++;
        if( Caso != 1 ) cout << endl;
        cout << "Field #" << Caso << ":" << endl;
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j )
                cout << Tablero[i][j];
            cout << endl;
        }
    }
    return 0;
}
