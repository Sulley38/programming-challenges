#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int Casos;
    cin >> Casos;
    while( Casos-- ) {
        int Candidatos, Eliminados = 0;
        cin >> Candidatos;
        cin.ignore(1);
        // Lee los nombres
        string s;
        vector<string> Nombres(Candidatos);
        for( int i = 0; i < Candidatos; ++i ) {
            getline(cin,s);
            Nombres[i] = s;
        }
        vector<int> Votos(Candidatos,0);
        vector< vector<int> > Pref;
        // Leer la entrada de las preferencias
        int In = 0, Cand;
        while( getline(cin,s) && s != "" ) {
            Pref.push_back(vector<int>(Candidatos));
            istringstream ss(s);
            for( int i = 0; i < Candidatos; ++i ) {
                ss >> Cand;
                Pref[In][i] = Cand-1;
            }
            In++;
        }

        // Primer recuento
        int Participacion = Pref.size();
        for( int i = 0; i < Participacion; ++i )
            Votos[Pref[i][0]]++;

        int Flag = -1, Ganador = -1, Menor, Index;
        vector<bool> Recontar(Participacion);
        while( Ganador == -1 && Eliminados < Candidatos ) {
            // Buscar un ganador y el menos votado
            Menor = 1001;
            for( int i = 0; i < Candidatos; ++i ) {
                if( Votos[i] > Participacion/2 ) {
                    Ganador = i;
                    i = Candidatos;
                }
                if( Votos[i] >= 0 && Votos[i] < Menor ) {
                    Menor = Votos[i];
                }
            }
            if( Ganador == -1 ) {
                // Si no hay ganador, eliminar el menos votado
                for( int i = 0; i < Candidatos; ++i ) {
                    if( Votos[i] == Menor ) {
                        Eliminados++;
                        Votos[i] = Flag;
                        for( int j = 0; j < Participacion; ++j ) { // Quitar candidato eliminado de las listas
                            Index = 0;
                            while( Index < Candidatos && Pref[j][Index] != i )
                                Index++;
                            Pref[j][Index] = -1;
                            while( Index > 0 && Pref[j][Index-1] == -1 ) Index--;
                            if( Index == 0 ) Recontar[j] = true; // Volver a contabilizar su voto
                        }
                    }
                }
                // Recontar votos
                for( int i = 0; i < Participacion; ++i ) {
                    if( Recontar[i] && Eliminados < Candidatos ) {
                        Index = 0;
                        while( Index < Candidatos && Pref[i][Index] == -1 ) Index++;
                        Votos[Pref[i][Index]]++;
                        Recontar[i] = false;
                    }
                }
                Flag--;
            }
        }
        // Mostrar los ganadores
        if( Ganador != -1 ) {
            cout << Nombres[Ganador] << endl;
        } else {
            for( int i = 0; i < Candidatos; ++i )
                if( Votos[i] == Flag+1 )
                    cout << Nombres[i] << endl;
        }
        if( Casos > 0 ) cout << endl;
    }

    return 0;
}
