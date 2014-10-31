#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N;
    while( cin >> M >> N ) {
        vector<int> S1(M), S2(N);
        for( int i = 0; i < M; ++i ) cin >> S1[i];
        for( int i = 0; i < N; ++i ) cin >> S2[i];
        // Calcula la subsecuencia mayor en cada i y j
        vector< vector<int> > C( M+1, vector<int>(N+1) );
        for( int i = 1; i <= M; ++i ) {
            for( int j = 1; j <= N; ++j ) {
                if( S1[i-1] == S2[j-1] ) C[i][j] = C[i-1][j-1] + 1;
                else C[i][j] = max( C[i][j-1], C[i-1][j] );
            }
        }
        cout << C[M][N] << endl;
    }
    return 0;
}
