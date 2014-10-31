#include <iostream>
#include <list>
#include <map>

using namespace std;

struct Cliente {
    int Precio, Cantidad, Linea;
};

bool menor( const Cliente& a, const Cliente& b ) { if( a.Precio != b.Precio ) return a.Precio < b.Precio; else return a.Linea < b.Linea; }
bool mayor( const Cliente& a, const Cliente& b ) { if( a.Precio != b.Precio ) return a.Precio > b.Precio; else return a.Linea < b.Linea; }

int main()
{
    map<int, list<Cliente> > Compradores;
    map<int, list<Cliente> > Vendedores;

    char c;
    int iTipoAccion = 0, iLinea = 1;
    Cliente Entrada;
    while( cin >> c >> iTipoAccion >> Entrada.Precio >> Entrada.Cantidad ) {
        Entrada.Linea = iLinea;
        if( c == 'C' ) {
            Compradores[iTipoAccion].push_front( Entrada );
            Compradores[iTipoAccion].sort( mayor );
        } else {
            Vendedores[iTipoAccion].push_front( Entrada );
            Vendedores[iTipoAccion].sort( menor );
        }

        bool Continuar = true;
        while( !Vendedores[iTipoAccion].empty() && !Compradores[iTipoAccion].empty() && Continuar ) {
            Cliente Comprador = Compradores[iTipoAccion].front(), Vendedor = Vendedores[iTipoAccion].front();
            if( Comprador.Precio >= Vendedor.Precio ) {
                int iNumero = min( Vendedor.Cantidad, Comprador.Cantidad );
                int iCoste = iNumero*( Comprador.Precio + Vendedor.Precio )/2;
                cout << iNumero << " #" << iTipoAccion << " = " << iCoste << " (" << Vendedor.Linea << "->" << Comprador.Linea << ")" << endl;

                if( Vendedor.Cantidad > Comprador.Cantidad ) {
                    Vendedores[iTipoAccion].front().Cantidad -= iNumero;
                    Compradores[iTipoAccion].erase( Compradores[iTipoAccion].begin() );
                } else {
                    Compradores[iTipoAccion].front().Cantidad -= iNumero;
                    Vendedores[iTipoAccion].erase( Vendedores[iTipoAccion].begin() );
                }
            } else {
                Continuar = false;
            }
        }

        iLinea++;
    }

    return 0;
}
