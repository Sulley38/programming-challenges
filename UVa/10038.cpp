#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    while( cin >> N ) {
        int Actual, Anterior, Dif;
        vector<bool> Diferencias(N);
        cin >> Anterior;
        // Lee el siguiente numero y calcula la diferencia
        for( int i = 1; i < N; ++i ) {
            cin >> Actual;
            Dif = Actual - Anterior;
            if( Dif < 0 ) Dif = -Dif;
            if( Dif < N ) Diferencias[Dif] = true;
            Anterior = Actual;
        }
        // Comprueba si se han dado todas las diferencias posibles
        bool Jolly = true;
        for( int i = 1; i < N; ++i ) {
            if( !Diferencias[i] ) {
                Jolly = false;
                i = N;
            }
        }
        // Muestra el resultado en pantalla
        if( Jolly )
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }

    return 0;
}
