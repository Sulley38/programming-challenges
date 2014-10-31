#include <iostream>
#include <map>

using namespace std;
typedef map<int,int>::iterator Iter;

int main()
{
    int Casos;
    cin >> Casos;
    while( Casos-- ) {
        int N;
        cin >> N;
        if( N == 1 ) { cout << "1" << endl; } else {
            // Busca los divisores primos
            int T = 2, Res = 1;
            map<int,int> Divisores;
            while( T*T <= N ) {
                if( N%T == 0 ) {
                    Divisores[T]++;
                    N /= T;
                } else {
                    T++;
                }
            }
            if( N != 1 ) Divisores[N]++;
            // Calcula el numero de divisores
            for( Iter i = Divisores.begin(); i != Divisores.end(); i++ ) Res *= i->second+1;
            cout << Res << endl;
        }
    }
    return 0;
}
