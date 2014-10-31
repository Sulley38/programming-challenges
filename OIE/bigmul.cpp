#include <iostream>
#include <vector>

#define MAX 1000000000

using namespace std;
typedef long long lint;

int main()
{
    int Grupos1, Grupos2;
    while( cin >> Grupos1 ) {
        // Leer la entrada
        vector<lint> Numero1(Grupos1);
        for( int i = 0; i < Grupos1; ++i ) cin >> Numero1[i];
        cin >> Grupos2;
        vector<lint> Numero2(Grupos2);
        for( int i = 0; i < Grupos2; ++i ) cin >> Numero2[i];
        // Operar
        vector<lint> Producto(Grupos1+Grupos2);
        for( int i = Grupos1-1; i >= 0; --i ) {
            for( int j = Grupos2-1; j >= 0; --j ) {
                long long int Mult = (Numero1[i])*(Numero2[j]);
                Producto[i+j] += Mult/MAX;
                int Llevada = 0;
                while( Producto[i+j-Llevada] >= MAX ) {
                    Producto[i+j-1-Llevada] += Producto[i+j-Llevada]/MAX;
                    Producto[i+j-Llevada] %= MAX;
                    Llevada++;
                }
                Producto[i+j+1] += Mult%MAX;
                Llevada = 0;
                while( Producto[i+j+1-Llevada] >= MAX ) {
                    Producto[i+j-Llevada] += Producto[i+j+1-Llevada]/MAX;
                    Producto[i+j+1-Llevada] %= MAX;
                    Llevada++;
                }

            }
        }
        // No eres mas que un cero a la izquierda!!
        int Borrar = 0;
        for( int i = 0; i < Grupos1+Grupos2; ++i ) if( Producto[i] == 0 ) Borrar++; else break;
        // Mostrar
        cout << Grupos1+Grupos2-Borrar;
        for( int i = Borrar; i < Grupos1+Grupos2; ++i ) cout << " " << Producto[i];
        cout << endl;
    }

    return 0;
}
