#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, M, Caso = 1;
    while( cin >> N ) {
        // Guarda los nombres y sus amigos
        map<string,int> Indice;
        vector<string> People(N);
        for( int i = 0; i < N; ++i ) {
            cin >> People[i];
            Indice[People[i]] = i;
        }
        cin >> M;
        string a, b;
        vector< vector<bool> > Relacion( N, vector<bool>(N) ); // True para amistad directa
        for( int i = 0; i < M; ++i ) {
            cin >> a >> b;
            Relacion[Indice[a]][Indice[b]] = true;
            Relacion[Indice[b]][Indice[a]] = true;
        }
        // Recorre las amistades de cada uno usando BFS
        vector<bool> Visitado(N); // True cuando ya esta analizado
        int Analizados = 0, Max = 0, Min = 10000000;
        while( Analizados < N ) {
            int Grupo = 0, Index = 0;
            while( Visitado[Index] ) Index++; // Busca la siguiente persona no analizada
            Visitado[Index] = true;
            queue<int> Cola;
            Cola.push(Index);
            while( !Cola.empty() ) { // Recorre todo el grupo de amigos
                Index = Cola.front(); Cola.pop();
                for( int i = 0; i < N; ++i ) { // Encola los amigos aun no visitados
                    if( Relacion[Index][i] && !Visitado[i] ) {
                        Cola.push(i);
                        Visitado[i] = true; // Evita encolar dos veces el mismo amigo
                    }
                }
                Grupo++; Analizados++;
            }
            // Determina si el grupo es un maximo o un minimo
            Max = max( Grupo, Max );
            Min = min( Grupo, Min );
        }

        cout << "Caso #" << Caso << endl;
        cout << "minimo grupo de amigos: " << Min << endl;
        cout << "maximo grupo de amigos: " << Max << endl;
        Caso++;
    }
    return 0;
}
