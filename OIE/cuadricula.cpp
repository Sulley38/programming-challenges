#include <iostream>
#include <vector>

using namespace std;

char SumarChar( const char& c ) {
    if( c == 'z' ) return 'A';
    else return c+1;
}

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    vector< vector<char> > Cuad( n, vector<char>( m ) );
    // Pintar paredes
    for( i = 0; i < m; i++ ) Cuad[0][i] = '*';
    for( i = 0; i < m; i++ ) Cuad[n-1][i] = '*';
    for( i = 1; i < n; i++ ) Cuad[i][0] = '*';
    for( i = 1; i < n; i++ ) Cuad[i][m-1] = '*';

    i = 1; j = 1;
    char c = 'a';
    Cuad[i][j] = c;
    while( Cuad[i][j+1] == 0 || Cuad[i][j-1] == 0 || Cuad[i+1][j] == 0 || Cuad[i-1][j] == 0 ) {
        c = SumarChar( c );
        if( Cuad[i][j+1] == 0 ) j++;
        else if( Cuad[i+1][j] == 0 ) i++;
        else if( Cuad[i][j-1] == 0 ) j--;
        else if( Cuad[i-1][j] == 0 ) i--;
        Cuad[i][j] = c;
    }

    // Mostrar en pantalla
    for( i = 0; i < n; i++) {
        for( j = 0; j < m; j++ )
            cout << Cuad[i][j];
        cout << endl;
    }

    return 0;
}
