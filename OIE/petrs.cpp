#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0, Maximo = 0, Suma = 0;
    cin >> N;
    vector<int> Puntuaciones( N );

    for( int i = 0; i < N; i++ )
        cin >> Puntuaciones[i];

    for( int j = 0; j < N; j++ ) {
        Suma += Puntuaciones[j];
        if( Suma > Maximo ) Maximo = Suma;
        if( Suma < 0 ) Suma = 0;
    }

    cout << Maximo << endl;

    return 0;
}
