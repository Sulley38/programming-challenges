#include <iostream>

using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;
    int Dinero = N, Negativo = 0, Gasto;
    for( int i = 0; i < 5; ++i ) {
        Dinero += K;
        cin >> Gasto;
        Dinero -= Gasto;
        if( Dinero < 0 )
            Negativo++;
    }

    cout << Dinero << endl << Negativo << endl;

    return 0;
}
