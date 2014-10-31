#include <iostream>

using namespace std;

int main()
{
    string Verbo;
    cin >> Verbo;
    string Raiz( Verbo, 0, Verbo.size()-2 ), Terminacion( Verbo, Verbo.size()-2, 2 ), VocalTematica, VocalAux;
    if( Terminacion == "ar" ){
        VocalTematica = "a"; VocalAux = "a";
    } else if( Terminacion == "er" ) {
        VocalTematica = "e"; VocalAux = "e";
    } else {
        VocalTematica = "i"; VocalAux = "e";
    }

    cout << "yo " << Raiz << "o" << endl;
    cout << "tu " << Raiz << VocalAux << "s" << endl;
    cout << "el " << Raiz << VocalAux << endl;
    cout << "nosotros " << Raiz << VocalTematica << "mos" << endl;
    if( Terminacion == "ir" )
        cout << "vosotros " << Raiz << VocalTematica << "s" << endl;
    else
        cout << "vosotros " << Raiz << VocalTematica << "is" << endl;
    cout << "ellos " << Raiz << VocalAux << "n" << endl;

    return 0;
}
