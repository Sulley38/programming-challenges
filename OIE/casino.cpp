#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string,int> Clientes;
    string Nombre, Op;

    while( cin >> Nombre >> Op ){
        if( Op == "in" ) {

            if( Clientes.find( Nombre ) == Clientes.end() )
                Clientes[Nombre] = 0;
            else
                cout << Nombre << " is in!" << endl;

        } else if( Op == "out" ){

            if( Clientes.find( Nombre ) == Clientes.end() ) {
                cout << Nombre << " is not in!" << endl;
            } else {
                cout << Nombre << " wins " << Clientes[Nombre] << endl;
                Clientes.erase( Nombre );
            }

        } else {

            if( Clientes.find( Nombre ) == Clientes.end() ) {
                cout << Nombre << " is not in!" << endl;
                cin.ignore( 32, '\n' );
            } else {
                int iCantidad = 0;
                cin >> iCantidad;
                Clientes[Nombre] += iCantidad;
            }

        }
    }

    cout << "----------" << endl;
    map<string,int>::iterator it;
    for( it = Clientes.begin(); it != Clientes.end(); it++ ) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
