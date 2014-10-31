#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long lint;

// Jugada: asigna un numero de 11 cifras, la primera significa:
// 0 = High card, 1 = Pair, 2 = Two pairs, 3 = Three of a kind, 4 = Straight, 5 = Flush, 6 = Full House, 7 = Four of a kind, 8 = Straight flush
// Las 10 restantes son los valores de las cartas
lint Mano( const vector<int>& Cartas, const vector<char>& Palos, const int& Start )
{
    bool Color = true;
    vector<int> Valores(13); // Cantidad de veces que aparece un valor
    // Comprobar si todas las cartas son del mismo palo y guardar los valores
    for( int i = Start; i < Start+5; ++i ) {
        if( Palos[i] != Palos[Start] )
            Color = false;
        Valores[Cartas[i]-2]++;
    }
    // Asigna los codigos
    if( Color ) {
        if( Cartas[Start+1] == Cartas[Start]+1 && Cartas[Start+2] == Cartas[Start]+2 && Cartas[Start+3] == Cartas[Start]+3 && Cartas[Start+4] == Cartas[Start]+4 ) // Straight flush
            return 80000000000 + Cartas[Start+4];
        else // Flush
            return 50000000000 + Cartas[Start+4]*100000000 + Cartas[Start+3]*1000000 + Cartas[Start+2]*10000 + Cartas[Start+1]*100 + Cartas[Start];
    } else {
        if( Cartas[Start+1] == Cartas[Start]+1 && Cartas[Start+2] == Cartas[Start]+2 && Cartas[Start+3] == Cartas[Start]+3 && Cartas[Start+4] == Cartas[Start]+4 ) // Straight
            return 40000000000 + Cartas[Start+4];
        // Buscar coincidencias en valor
        int Trio = -1, ParejaA = -1, ParejaB = -1, KickerA = -1, KickerB = -1, KickerC = -1;
        for( int i = 12; i >= 0; --i ) {
            if( Valores[i] == 4 ) { // Four of a kind
                return 70000000000 + i + 2;
            } else if( Valores[i] == 3 ) {
                Trio = i+2;
            } else if( Valores[i] == 2 ) {
                if( ParejaA == -1 ) ParejaA = i+2;
                else ParejaB = i+2;
            } else if( Valores[i] == 1 ) {
                if( KickerA == -1 ) KickerA = i+2;
                else if( KickerB == -1 ) KickerB = i+2;
                else if( KickerC == -1 ) KickerC = i+2;
            }
        }
        // Determinar la mano
        if( Trio != -1 && ParejaA != -1 ) { // Full house
            return 60000000000 + Trio;
        } else if( Trio != -1 ) { // Three of a kind
            return 30000000000 + Trio;
        } else if( ParejaA != -1 && ParejaB != -1 ) { // Two pairs
            return 20000000000 + ParejaA*10000 + ParejaB*100 + KickerA;
        } else if( ParejaA != -1 ) { // Pair
            return 10000000000 + ParejaA*1000000 + KickerA*10000 + KickerB*100 + KickerC;
        } else { // High card
            return Cartas[Start+4]*100000000 + Cartas[Start+3]*1000000 + Cartas[Start+2]*10000 + Cartas[Start+1]*100 + Cartas[Start];
        }
    }
}

int main()
{
    vector<char> Entrada(20);
    vector<int> Cartas(10);
    vector<char> Palos(10);
    while( cin >> Entrada[0] ) {
        // Leer la entrada y asignar valores
        for( int i = 1; i < 20; ++i )
            cin >> Entrada[i];
        for( int i = 0; i < 20; i += 2 ) {
            if( Entrada[i] == 'T' ) Cartas[i/2] = 10;
            else if( Entrada[i] == 'J' ) Cartas[i/2] = 11;
            else if( Entrada[i] == 'Q' ) Cartas[i/2] = 12;
            else if( Entrada[i] == 'K' ) Cartas[i/2] = 13;
            else if( Entrada[i] == 'A' ) Cartas[i/2] = 14;
            else Cartas[i/2] = Entrada[i]-'0';
            Palos[i/2] = Entrada[i+1];
        }
        // Ordenar de menor a mayor
        sort( Cartas.begin(), Cartas.begin()+5 );
        sort( Cartas.begin()+5, Cartas.end() );
        // Buscar el valor de cada mano
        lint JugadaA = Mano( Cartas, Palos, 0 ), JugadaB = Mano( Cartas, Palos, 5 );
        if( JugadaA > JugadaB )
            cout << "Black wins." << endl;
        else if( JugadaB > JugadaA )
            cout << "White wins." << endl;
        else
            cout << "Tie." << endl;
    }

    return 0;
}
