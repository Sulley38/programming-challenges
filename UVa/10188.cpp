#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, Count = 1;
    while( cin >> N && N != 0 ) {
        // Leer las soluciones y distinguir los numeros
        vector<string> Correcto(N);
        string NumCorrecto, NumEnvio;
        cin.ignore(1);
        for( int i = 0; i < N; ++i ) {
            getline(cin,Correcto[i]);
            for( int j = 0; j < int(Correcto[i].size()); ++j )
                if( Correcto[i][j] >= '0' && Correcto[i][j] <= '9' )
                    NumCorrecto.push_back(Correcto[i][j]);
        }

        cin >> M;
        vector<string> Envio(M);
        cin.ignore(1);
        for( int i = 0; i < M; ++i ) {
            getline(cin,Envio[i]);
            for( int j = 0; j < int(Envio[i].size()); ++j )
                if( Envio[i][j] >= '0' && Envio[i][j] <= '9' )
                    NumEnvio.push_back(Envio[i][j]);
        }
        // Compararlas
        cout << "Run #" << Count << ": ";
        if( NumCorrecto == NumEnvio ) {
            if( N == M ) {
                bool Bien = true;
                for( int i = 0; i < N; ++i )
                    if( Correcto[i] != Envio[i] )
                        Bien = false;
                if( Bien )
                    cout << "Accepted" << endl;
                else
                    cout << "Presentation Error" << endl;
            } else {
                cout << "Presentation Error" << endl;
            }
        } else {
            cout << "Wrong Answer" << endl;
        }
        Count++;
    }


    return 0;
}
