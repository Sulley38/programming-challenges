#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef pair<int,string> Pareja;
typedef map< string, pair<int,int> > Lista;

bool Comparar( Pareja i, Pareja j )
{
    if( i.first == j.first ) return i.second < j.second;
    else return i.first > j.first;
}

int main()
{
    int iPuntuacion = 0, iNumCorte = 0;
    string Entrada;

    Lista Jugadores;
    while( cin >> Entrada >> iPuntuacion ) {
        if( Entrada == "corte" ) {
            iNumCorte++;
            for( Lista::iterator it = Jugadores.begin(); it != Jugadores.end(); it++ ) {
                if( it->second.first < iPuntuacion && it->second.second == 0 ) {
                    it->second.second = iNumCorte;
                }
            }
        } else {
            if( iNumCorte == 0 ) {
                Jugadores[Entrada].first += iPuntuacion;
            } else {
                if( Jugadores.find( Entrada ) == Jugadores.end() ) {
                    cout << Entrada << "?" << endl;
                } else {
                    if( Jugadores[Entrada].second != 0 ) {
                        cout << Entrada << " OUT" << endl;
                    } else {
                        Jugadores[Entrada].first += iPuntuacion;
                    }
                }
            }
        }
    }

    vector<Pareja> Ordenar;
    for( Lista::iterator it = Jugadores.begin(); it != Jugadores.end(); it++ ) {
            Ordenar.push_back( Pareja(it->second.first, it->first) );
    }
    sort( Ordenar.begin(), Ordenar.end(), Comparar );

    for( int i = 0; i < int(Ordenar.size()); i++ ) {
        if( Jugadores[Ordenar[i].second].second == 0 )
            cout << "** " << Ordenar[i].second << " " << Ordenar[i].first << endl;
        else
            cout << "C" << Jugadores[Ordenar[i].second].second << " " << Ordenar[i].second << " " << Ordenar[i].first << endl;
    }

    return 0;
}
