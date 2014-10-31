#include <cmath>
#include <iostream>

using namespace std;

int Factorial( int Numero )
{
    int Res = Numero;
    while( Numero > 1 ) {
        Numero--;
        Res *= Numero;
    }
    return Res;
}

int Factorial( int Numero, int Fin )
{
    int Res = Numero;
    while( Numero > Fin+1 ) {
        Numero--;
        Res *= Numero;
    }
    return Res;
}

int main()
{
    int N;
    cin >> N;
    while( N != 0 ) {
        cout << Factorial( N*N, N*N-N ) / Factorial( N ) - Factorial( N ) << endl;
        cin >> N;
    }

    return 0;
}
