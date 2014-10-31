#include <iostream>
#include <map>
#include <set>

using namespace std;
typedef map<string,int> Mapa;

int main()
{
    Mapa Repeticiones;
    string Palabra;
    while( cin >> Palabra ) {
        Repeticiones[Palabra]++;
    }

    int iValorMaximo = 0;
    for( Mapa::iterator it = Repeticiones.begin(); it != Repeticiones.end(); it++ ) {
        if( it->second > iValorMaximo ) {
            iValorMaximo = it->second;
        }
    }

    set<string> sRepetidas;
    for( Mapa::iterator it = Repeticiones.begin(); it != Repeticiones.end(); it++ ) {
        if( it->second == iValorMaximo ) {
            sRepetidas.insert( it->first );
        }
    }

    cout << iValorMaximo << endl;
    for( set<string>::iterator it = sRepetidas.begin(); it != sRepetidas.end(); it++ ) {
        cout << *it << endl;
    }

    return 0;
}
