#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout.setf( ios::fixed );
    cout.precision(2);
    int n;
    while( cin >> n && n != 0 ) {
        vector<double> Gastos(n);
        double Suma = 0.0;
        for( int i = 0; i < n; ++i ) {
            cin >> Gastos[i];
            Suma += Gastos[i];
        }
        // Calcular lo que debe pagar cada uno
        double Media = Suma / n, Positivo = 0.0, Negativo = 0.0, Mov;
        for( int i = 0; i < n; ++i ) {
            Mov = int((Gastos[i] - Media) * 100.0) / 100.0;
            if( Mov < 0 )
                Negativo -= Mov;
            else
                Positivo += Mov;
        }

        if( Negativo > Positivo )
            cout << "$" << Negativo << endl;
        else
            cout << "$" << Positivo << endl;
    }

    return 0;
}
