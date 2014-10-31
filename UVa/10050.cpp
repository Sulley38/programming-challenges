#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Casos;
    cin >> Casos;
    while( Casos-- ) {
        int Dias, Partidos, Parametro, Res = 0;
        cin >> Dias >> Partidos;
        vector<bool> Huelga(Dias+1,false);
        for( int i = 0; i < Partidos; ++i ) {
            cin >> Parametro;
            // Marcar todos los dias que toca huelga
            for( int j = Parametro; j <= Dias; j += Parametro ) {
                if( (j-6)%7 != 0 && (j-7)%7 != 0 ) { // Si no es viernes o sabado
                    if( !Huelga[j] ) Res++;
                    Huelga[j] = true;
                }
            }
        }
        cout << Res << endl;
    }

    return 0;
}
