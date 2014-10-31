#include <iostream>
#include <vector>

#define MUCHO 1000000

using namespace std;
int Valores[4] = { 1, 5, 8, 14 };

int main()
{
    int n;
    while( cin >> n ) {
        if( n == -1 ) break;

        vector<int> Coste( n+1, MUCHO );
        Coste[0] = 0;
        for( int i = 1; i <= n; ++i )
            for( int j = 0; j <= 3; ++j )
                if( i-Valores[j] >= 0 )
                    Coste[i] = min( Coste[i], 1 + Coste[i-Valores[j]] );

        cout << Coste[n] << endl;
    }
    return 0;
}
