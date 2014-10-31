#include <iostream>

using namespace std;

int main()
{
    int Casos;
    cin >> Casos;
    while( Casos-- ) {
        int n, Profundidad, Valor = 0, Coste = 0, BeneficioActual = 0, BeneficioMax = 0, TargetProf = 0;
        cin >> Profundidad;
        for( int i = 1; i < Profundidad+1; i++ ) {
            cin >> n;
            Valor += n;
            Coste += i;
            BeneficioActual = Valor - Coste;
            if( BeneficioActual > BeneficioMax ) {
                BeneficioMax = BeneficioActual;
                TargetProf = i;
            }
        }
        cout << BeneficioMax << " " << TargetProf << endl;
    }

    return 0;
}
