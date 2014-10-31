#include <iostream>
#include <vector>

using namespace std;

int JugarTieBreak();
int GetExtra();
void PrintPuntuaciones( const vector<int>& Player1, const vector<int>& Player2 );

int JugarTieBreak()
{
    char c;
    pair<int,int> Desempate;
    while( cin >> c ) {
        if( c == '0' ) {
            Desempate.first++;
            if( Desempate.first >= 7 && Desempate.first - Desempate.second >= 2 )
                return 0;
        } else {
            Desempate.second++;
            if( Desempate.second >= 7 && Desempate.second - Desempate.first >= 2 )
                return 1;
        }
    }
    return -1;
}

int GetExtra()
{
    char c;
    int iBolas = 0;
    while( cin >> c ) {
        iBolas++;
    }
    return iBolas;
}

void PrintPuntuaciones( const vector<int>& Player1, const vector<int>& Player2 )
{
    cout << "Jugador 0:";
    for( int i = 0; i < int(Player1.size()); i++ ) {
        cout << " " << Player1[i];
    }
    cout << endl;

    cout << "Jugador 1:";
    for( int i = 0; i < int(Player2.size()); i++ ) {
        cout << " " << Player2[i];
    }
    cout << endl;
}

int main()
{
    char c;
    pair<int,int> Puntos;
    pair<int,int> Juegos;
    pair<int,int> Sets;
    vector<int> Resultado0( 1 );
    vector<int> Resultado1( 1 );
    int iGanador = -1, iExtra = 0;

    while( cin >> c ) {
        if( c == '0' ) {
            Puntos.first++;
            if( int(Resultado1.size()) <= Sets.first + Sets.second ) {
                Resultado0.push_back( 0 );
                Resultado1.push_back( 0 );
            }
            if( Puntos.first >= 4 && Puntos.first - Puntos.second >= 2 ) {
                Juegos.first++;
                Resultado0[Sets.first+Sets.second]++;

                if( Juegos.first >= 6 ) {
                    if( Juegos.first - Juegos.second >= 2 ) {
                        Sets.first++;
                        if( Sets.first == 3 ) {
                            iGanador = 0;
                            iExtra = GetExtra();
                        }
                        Juegos.first = 0;
                        Juegos.second = 0;
                    }
                    else if( Juegos.first == Juegos.second && Sets.first + Sets.second != 4 ) {
                        int i = JugarTieBreak();
                        if( i == 0 ) {
                            Juegos.first++;
                            Resultado0[Sets.first+Sets.second]++;
                            Sets.first++;
                            if( Sets.first == 3 ) {
                                iGanador = 0;
                                iExtra = GetExtra();
                            }
                        }
                        else if( i == 1 ) {
                            Juegos.second++;
                            Resultado1[Sets.first+Sets.second]++;
                            Sets.second++;
                            if( Sets.second == 3 ) {
                                iGanador = 1;
                                iExtra = GetExtra();
                            }
                        }
                        Juegos.first = 0;
                        Juegos.second = 0;
                    }
                }

                Puntos.first = 0;
                Puntos.second = 0;
            }
        }
        else {
            Puntos.second++;
            if( int(Resultado1.size()) <= Sets.first + Sets.second ) {
                Resultado0.push_back( 0 );
                Resultado1.push_back( 0 );
            }
            if( Puntos.second >= 4 && Puntos.second - Puntos.first >= 2 ) {
                Juegos.second++;
                Resultado1[Sets.first+Sets.second]++;

                if( Juegos.second >= 6 ) {
                    if( Juegos.second - Juegos.first >= 2 ) {
                        Sets.second++;
                        if( Sets.second == 3 ) {
                            iGanador = 1;
                            iExtra = GetExtra();
                        }
                        Juegos.first = 0;
                        Juegos.second = 0;
                    }
                    else if( Juegos.first == Juegos.second && Sets.first + Sets.second != 4 ) {
                        int i = JugarTieBreak();
                        if( i == 0 ) {
                            Juegos.first++;
                            Resultado0[Sets.first+Sets.second]++;
                            Sets.first++;
                            if( Sets.first == 3 ) {
                                iGanador = 0;
                                iExtra = GetExtra();
                            }
                        }
                        else if( i == 1 ) {
                            Juegos.second++;
                            Resultado1[Sets.first+Sets.second]++;
                            Sets.second++;
                            if( Sets.second == 3 ) {
                                iGanador = 1;
                                iExtra = GetExtra();
                            }
                        }
                        Juegos.first = 0;
                        Juegos.second = 0;
                    }
                }

                Puntos.first = 0;
                Puntos.second = 0;
            }
        }

    }

    if( iGanador == 0 ) {
        cout << "Gana 0" << endl;
    } else if( iGanador == 1 ) {
        cout << "Gana 1" << endl;
    } else {
        cout << "No ha acabado" << endl;
    }
    PrintPuntuaciones( Resultado0, Resultado1 );
    if( iExtra > 0 )
        cout << iExtra << " extra" << endl;

    return 0;
}
