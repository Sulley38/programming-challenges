#include <iostream>
#include <vector>

using namespace std;
typedef pair<long long,long long> PII;

long long MCD( long long a, long long b );

int main()
{
    int casos;
    cin >> casos;
    while( casos-- ) {
        // Leer entrada
        vector<PII> Fracciones( 0 );
        PII Entrada;
        while( cin >> Entrada.first ) {
            cin.get(); cin >> Entrada.second;
            Fracciones.push_back( Entrada );
            if( cin.get() == '=' ) break;
        }
        // Sumar todo
        while( int(Fracciones.size()) > 1 ) {
            Fracciones[0].first = Fracciones[0].first * Fracciones[1].second + Fracciones[1].first * Fracciones[0].second;
            Fracciones[0].second = Fracciones[0].second * Fracciones[1].second;
            Fracciones.erase( Fracciones.begin()+1 );
        }
        // Calcular maximo comun divisor
        long long divisor;
        if( Fracciones[0].second > Fracciones[0].first )
            divisor = MCD( Fracciones[0].second, Fracciones[0].first );
        else
            divisor = MCD( Fracciones[0].first, Fracciones[0].second );

        cout << Fracciones[0].first / divisor << "/" << Fracciones[0].second / divisor << endl;

    }

    return 0;
}

long long MCD( long long a, long long b ) {
    if( b == 0 ) return a;
    else return MCD( b, a % b );
}
