#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
vector<int> Primos;

void GetPrimos()
{
    int Numero = 2;
    bool Test = true;
    while( Numero < 1000 ) {
        for( int i = 2; i < Numero; i++ )
            if( Numero % i == 0 ) Test = false;

        if( Test ) Primos.push_back( Numero );
        Numero++;
        Test = true;
    }
}

bool EsPrimo( const int& Numero )
{
    int Max = sqrt( Numero ), i = 0;
    while( Primos[i] <= Max && i < int(Primos.size()) ) {
        if( Numero % Primos[i] == 0 )
            return false;
        i++;
    }

    return true;
}

int PrimoCercano( const bool& Incremento, int Numero )
{
    while( !EsPrimo( Numero ) ) {
        if( Incremento == true ) Numero++;
        else Numero--;
    }

    return Numero;
}

int main()
{
    int iEntrada;
    GetPrimos();

    while( cin >> iEntrada ) {
        if( EsPrimo( iEntrada ) == true ) {
            cout << iEntrada << endl;
        } else {
            cout << ( PrimoCercano( false, iEntrada-1 ) + PrimoCercano( true, iEntrada+1 ) )/2 << endl;
        }
    }

    return 0;
}
