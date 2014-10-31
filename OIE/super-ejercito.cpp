#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct Militar {
    string Nombre, Rango;
    int Orden;
};

bool operator<(const Militar &a, const Militar &b) { //cierto si 'b' debe ir antes de 'a'
    if( a.Rango == "coronel" ) {
        if( b.Rango == "coronel" && a.Orden > b.Orden )
            return true;
        return false;
    } else if( a.Rango == "capitan" ) {
        if( b.Rango == "coronel" || ( b.Rango == "capitan" && a.Orden > b.Orden ) )
            return true;
        else
            return false;
    } else if( a.Rango == "sargento" ) {
        if( b.Rango == "coronel" || b.Rango == "capitan" || ( b.Rango == "sargento" && a.Orden > b.Orden ) )
            return true;
        else
            return false;
    } else {
        if( b.Rango != "soldado" || ( b.Rango == "soldado" && a.Orden > b.Orden ) )
            return true;
        else
            return false;
    }
}

int main()
{
    int iColas = 0;
    cin >> iColas;
    cin.ignore( 1, '\n' );

    priority_queue<Militar> cola[iColas];
    int iOrden = 0;
    string Entrada;
    for( int i = 0; i < iColas; i++ ) {
        Militar Pers;
        getline( cin, Entrada );
        istringstream iss( Entrada );
        while( iss >> Pers.Nombre >> Pers.Rango ) {
            Pers.Orden = iOrden++;
            cola[i].push( Pers );
        }
    }
    cin.ignore( 1, '\n' );

    string Accion;
    int iColaActual = 0;
    cout << "SALIDAS" << endl << "-------" << endl;
    while( getline( cin, Entrada ) ) {
        Militar Pers;
        istringstream iss( Entrada );
        iss >> Accion;
        if( Accion == "SALE" ) {
            iss >> iColaActual;
            if( iColaActual <= iColas && iColaActual > 0 && !cola[iColaActual-1].empty() ) {
                Pers = cola[iColaActual-1].top();
                cola[iColaActual-1].pop();
                cout << Pers.Nombre << endl;
            }
        } else {
            iss >> Pers.Nombre >> Pers.Rango >> iColaActual;
            Pers.Orden = iOrden++;
            if( iColaActual <= iColas && iColaActual > 0 )
                cola[iColaActual-1].push( Pers );
        }

    }

    cout << endl << "CONTENIDOS FINALES" << endl << "------------------" << endl;
    for( int i = 0; i < iColas; i++ ) {
        int size = cola[i].size();
        cout << "cola " << i+1 << ":";
        for( int j = 0; j < size; j++ ) {
            Militar Mil = cola[i].top();
            cola[i].pop();
            cout << " " << Mil.Nombre;
        }
        cout << endl;
    }

    return 0;
}
