#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector< vector<char> > Tab(N,vector<char>(N));
    for( int i = 0; i < N; ++i )
        for( int j = 0; j < N; ++j )
            cin >> Tab[i][j];

    char c;
    bool Win = false;
    for( int i = N-1; i >= 0; --i ) {
        for( int j = 0; j < N; ++j ) {
            c = Tab[i][j];
            if( c != '.' ) {
                if( i+2 < N && Tab[i+1][j] == c && Tab[i+2][j] == c ) { Win = true; j = N; i = 0; }
                if( i-2 > -1 && Tab[i-1][j] == c && Tab[i-2][j] == c ) { Win = true; j = N; i = 0; }
                if( j+2 < N && Tab[i][j+1] == c && Tab[i][j+2] == c ) { Win = true; j = N; i = 0; }
                if( j-2 > -1 && Tab[i][j-1] == c && Tab[i][j-2] == c ) { Win = true; j = N; i = 0; }
                if( j-2 > -1 && i-2 > -1 && Tab[i-1][j-1] == c && Tab[i-2][j-2] == c ) { Win = true; j = N; i = 0; }
                if( j-2 > -1 && i+2 < N && Tab[i+1][j-1] == c && Tab[i+2][j-2] == c ) { Win = true; j = N; i = 0; }
                if( j+2 < N && i-2 > -1 && Tab[i-1][j+1] == c && Tab[i-2][j+2] == c ) { Win = true; j = N; i = 0; }
                if( j+2 < N && i+2 < N && Tab[i+1][j+1] == c && Tab[i+2][j+2] == c ) { Win = true; j = N; i = 0; }
            }
        }
    }

    if( Win )
        cout << c << endl;
    else
        cout << "ongoing" << endl;

    return 0;
}
