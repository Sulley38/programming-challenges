#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef pair<int,string> Criterio;
struct Robot {
    Robot();
    int Wins, Grupo;
    string Name, Pareja;
    vector<string> Combatidos;
};

struct Grupo {
    Grupo();
    bool Cerrado;
    int Combates, Necesarios;
    pair<string,string> Clasificados;
};

Robot::Robot() {
    Wins = 0; Grupo = 0;
}

Grupo::Grupo() {
    Cerrado = false; Combates = 0; Necesarios = 0;
}

bool Orden( const Criterio& A, const Criterio& B ) {
    if( A.first == B.first ) return A.second < B.second;
    else return B.first < A.first;
}

int Factorial( int N ) {
    if( N == 0 ) return 1;
    else return N*Factorial( N-1 );
}

bool IsElegible( const Robot& A, const Robot& B, const int& M ) {
    if( M == 0 ) {
        // Comprobar: mismo grupo, aun no han luchado
        if( A.Grupo != B.Grupo ) return false;
        for( int i = 0; i < int( A.Combatidos.size() ); i++ ) if( A.Combatidos[i] == B.Name ) return false;
        return true;
    } else {
        // Comprobar: emparejados
        if( A.Pareja != B.Name || B.Pareja != A.Name ) return false;
        return true;
    }
}

pair<string,string> Clasifican( map<string,Robot>& Rob, const int& G ) {
    vector<Criterio> RobotsOrdenado;
    for( map<string,Robot>::iterator it = Rob.begin(); it != Rob.end(); it++ )
        if( it->second.Grupo == G ) RobotsOrdenado.push_back( Criterio(it->second.Wins, it->first) );
    sort( RobotsOrdenado.begin(), RobotsOrdenado.end(), Orden );
    return pair<string,string>( RobotsOrdenado[0].second, RobotsOrdenado[1].second );
}

string Pareja( const string& N, vector<string>& Clasificados ) {
    int P = 0;
    while( P < 15 && Clasificados[P] != N ) P++;
    Clasificados[P] = "";
    if( P == 0 || P == 1 ) {
        Clasificados[8] = N;
        return Clasificados[9];
    } else if( P == 2 || P == 3 ) {
        Clasificados[9] = N;
        return Clasificados[8];
    } else if( P == 4 || P == 5 ) {
        Clasificados[10] = N;
        return Clasificados[11];
    } else if( P == 6 || P == 7 ) {
        Clasificados[11] = N;
        return Clasificados[10];
    } else if( P == 8 || P == 9 ) {
        Clasificados[12] = N;
        return Clasificados[13];
    } else if( P == 10 || P == 11 ) {
        Clasificados[13] = N;
        return Clasificados[12];
    } else if( P == 12 || P == 13 ) {
        Clasificados[14] = N;
        if( P == 13 ) Clasificados[13] = Clasificados[12];
        return "Winner";
    }
    return "";
}

void Print( vector<string>& Clasificacion ) {
    int Cuenta = 0;
    vector<string> Semis, Cuartos;
    for( int i = 11; i >= 0; i-- ) {
        if( Clasificacion[i] != "" ) {
            if( Cuenta < 2 ) Semis.push_back( Clasificacion[i] );
            else Cuartos.push_back( Clasificacion[i] );
            Cuenta++;
        }
    }
    stable_sort( Semis.begin(), Semis.end() );
    stable_sort( Cuartos.begin(), Cuartos.end() );
    cout << "-----" << endl << Clasificacion[14] << endl << Clasificacion[13] << endl <<
            Semis[0] << " " << Semis[1] << endl << Cuartos[0] << " " << Cuartos[1] << " " <<
            Cuartos[2] << " " << Cuartos[3] << endl;
}

int main()
{
    map<string,Robot> Robots;
    vector<Grupo> Grupos( 4 );
    vector<string> Clasis( 15 ); // Nombres de los robots clasificados: En el orden de eliminatorias
    int num;
    string s;
    for( int i = 0; i < 4; i++ ) {
        cin >> num;
        Grupos[i].Necesarios = Factorial( num ) / (2*Factorial( num-2 ));
        while( num-- ) {
            cin >> s;
            Robots[s].Name = s;
            Robots[s].Grupo = i;
        }
    }

    string a, b;
    int w, Modo = 0, CurrentGroup; // 0 para liguilla, 1 para eliminatorias
    while( cin >> a >> b >> w ) {
        if( IsElegible( Robots[a], Robots[b], Modo ) ) {
            if( Modo == 0 ) {
                // Anyade la informacion sobre el combate a los robots y al grupo
                CurrentGroup = Robots[a].Grupo;
                if( w == 1 ) Robots[a].Wins++;
                else Robots[b].Wins++;
                Robots[a].Combatidos.push_back( b );
                Robots[b].Combatidos.push_back( a );
                Grupos[CurrentGroup].Combates++;
                // Comprueba si el grupo esta cerrado
                if( Grupos[CurrentGroup].Combates == Grupos[CurrentGroup].Necesarios ) {
                    Grupos[CurrentGroup].Clasificados = Clasifican( Robots, CurrentGroup );
                    Grupos[CurrentGroup].Cerrado = true;
                }
                // Si todos los grupos estan cerrados, avanza a las eliminatorias, empareja y muestra los clasificados
                if( Grupos[0].Cerrado && Grupos[1].Cerrado && Grupos[2].Cerrado && Grupos[3].Cerrado ) {
                    Modo = 1;
                    Clasis[0] = Grupos[0].Clasificados.first;
                    Clasis[1] = Grupos[3].Clasificados.second;
                    Robots[Clasis[0]].Pareja = Clasis[1];
                    Robots[Clasis[1]].Pareja = Clasis[0];
                    Clasis[2] = Grupos[1].Clasificados.first;
                    Clasis[3] = Grupos[2].Clasificados.second;
                    Robots[Clasis[2]].Pareja = Clasis[3];
                    Robots[Clasis[3]].Pareja = Clasis[2];
                    Clasis[4] = Grupos[2].Clasificados.first;
                    Clasis[5] = Grupos[1].Clasificados.second;
                    Robots[Clasis[4]].Pareja = Clasis[5];
                    Robots[Clasis[5]].Pareja = Clasis[4];
                    Clasis[6] = Grupos[3].Clasificados.first;
                    Clasis[7] = Grupos[0].Clasificados.second;
                    Robots[Clasis[6]].Pareja = Clasis[7];
                    Robots[Clasis[7]].Pareja = Clasis[6];
                    cout << Clasis[0] << endl << Clasis[1] << endl << Clasis[2] << endl << Clasis[3] << endl <<
                            Clasis[4] << endl << Clasis[5] << endl << Clasis[6] << endl << Clasis[7] << endl;
                }
            } else {
                // Buscar al robot y pasarlo de ronda
                if( w == 1 ) {
                    Robots[b].Pareja.clear();
                    string Match = Pareja( a, Clasis );
                    if( Match == "Winner" ) {
                        Print( Clasis );
                        return 0;
                    } else {
                        Robots[a].Pareja = Match;
                        if( Match != "" ) Robots[Match].Pareja = a;
                    }
                } else {
                    Robots[a].Pareja.clear();
                    string Match = Pareja( b, Clasis );
                    if( Match == "Winner" ) {
                        Print( Clasis );
                        return 0;
                    } else {
                        Robots[b].Pareja = Match;
                        if( Match != "" ) Robots[Match].Pareja = b;
                    }
                }
            }
        }
    }

    if( Modo == 0 ) cout << "??" << endl;

    return 0;
}
