#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

int main()
{
    int F,C;
    cin >> F >> C;
    vector< vector<int> > Tab( F, vector<int>(C) );
    vector< vector<bool> > Visitado( F, vector<bool>(C) );
    // Lee la entrada
    char c;
    for( int i = 0; i < F; ++i ) {
        for( int j = 0; j < C; ++j ) {
            cin >> c;
            if( c != 'T' )
                Tab[i][j] = c-'0';
        }
    }
    // Procesa el tablero con un BFS
    bool Meta = false;
    queue<PII> Casillas;
    Casillas.push(PII(1,0));
    while( !Casillas.empty() && !Meta ) {
        PII Ac = Casillas.front();
        Casillas.pop();
        // Encolar las dos opciones
        int Valor = Tab[Ac.first][Ac.second];
        if( Ac.first+1 < F && Ac.second-Valor >= 0 && !Visitado[Ac.first+1][Ac.second-Valor] ) {
            Casillas.push(PII(Ac.first+1,Ac.second-Valor));
            Visitado[Ac.first+1][Ac.second-Valor] = true;
            if( Ac.first+1 == F-1 && Ac.second-Valor == C-1 )
                Meta = true;
        }
        if( Ac.first+1 < F && Ac.second+Valor < C && !Visitado[Ac.first+1][Ac.second+Valor] ) {
            Casillas.push(PII(Ac.first+1,Ac.second+Valor));
            Visitado[Ac.first+1][Ac.second+Valor] = true;
            if( Ac.first+1 == F-1 && Ac.second+Valor == C-1 )
                Meta = true;
        }
    }

    if( Meta )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
