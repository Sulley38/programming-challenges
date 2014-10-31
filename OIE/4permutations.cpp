#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, C, M;
    while( cin >> N >> C >> M ) {
        int Num;
        vector< vector<int> > Ciclos(C,vector<int>());
        vector<int> Tam(C);

        // Lee los ciclos
        for( int i = 0; i < C; ++i ) {
            cin.ignore(1,'(');
            while( cin.peek() != ')' && cin >> Num )
                Ciclos[i].push_back(Num);
            cin.ignore(1,')');
            Tam[i] = Ciclos[i].size();
        }

        int Caso, Desfase;
        vector<int> Res(N+1);
        while( M-- ) {
            cin >> Caso;
            // Construye la respuesta
            for( int i = 0; i < C; ++i ) {
                Desfase = Caso % Tam[i];
                for( int j = 0; j < Tam[i]; ++j ) {
                    if( j+Desfase >= Tam[i] ) Desfase = ((j+Desfase) % Tam[i]) - j;
                    Res[Ciclos[i][j]] = Ciclos[i][j+Desfase];
                }
            }
            // Muestra en pantalla
            for( int i = 1; i < N; ++i )
                cout << Res[i] << " ";
            cout << Res[N] << endl;
        }
        cout << endl;
    }
    return 0;
}
