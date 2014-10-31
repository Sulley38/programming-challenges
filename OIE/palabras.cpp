#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string a, b;
    while( cin >> a >> b ) {
        int SA = a.size(), SB = b.size(), Long = 0;
        string Res;
        vector< vector<int> > T( SA, vector<int>(SB) );

        for( int i = 0; i < SA; ++i )
            for( int j = 0; j < SB; ++j ) {
                if( a[i] == b[j] ) {
                    if( i == 0 || j == 0 ) T[i][j] = 1;
                    else T[i][j] = T[i-1][j-1] + 1;
                    if( T[i][j] > Long ) {
                        Long = T[i][j];
                        Res = "";
                    }
                    if( Long == T[i][j] ) {
                        string Candidato = a.substr( i-Long+1, Long );
                        if( Res == "" || Candidato < Res ) Res = Candidato;
                    }
                }
            }

        cout << Res << endl;
    }

    return 0;
}
