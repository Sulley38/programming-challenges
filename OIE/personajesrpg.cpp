#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;
// Definiciones de las estructuras atributo y raza
struct Atributo {
    Atributo();
    int X, Y, B;
    string Nombre;
};

struct Raza {
    Raza();
    bool Definido;
    int Personajes;
    vector<Atributo> AtrList;
};
// Constructores de las estructuras
Atributo::Atributo() {
    X = 0; Y = 0; B = 0;
}

Raza::Raza() {
    Definido = false; Personajes = 0;
}
// Definiciones de los metodos
Atributo LeerAtr( const string& Nombre, const string& Parametro );
string GenerarAtr( vector<Atributo>& Atributos );
int CalcAtr( const Atributo& Attr );
// Semilla a usar
int Dado;

int main()
{
    cin >> Dado;

    char c;
    string nomraza;
    map<string,Raza> Razas;
    while( cin >> c >> nomraza ) {
        if( c == 'R' ) {
            // Lectura de nueva raza
            Razas[nomraza].Definido = true;
            int attr;
            cin >> attr;
            string attrname, param;
            while( attr-- ) {
                cin >> attrname >> param;
                Razas[nomraza].AtrList.push_back( LeerAtr( attrname, param ) );
            }
        } else {
            // Creacion de personaje
            int pers;
            cin >> pers;
            if( !Razas[nomraza].Definido ) {
                cout << "Raza " << nomraza << " no existe." << endl;
            } else {
                while( pers-- )
                    cout << nomraza << " #" << ++Razas[nomraza].Personajes << ":" << GenerarAtr( Razas[nomraza].AtrList ) << "." << endl;
            }
        }
    }

    return 0;
}

Atributo LeerAtr( const string& Nombre, const string& Parametro ) {
    Atributo At;
    At.Nombre = Nombre;
    istringstream iss( Parametro );
    char c;
    iss >> At.X >> c >> At.Y >> At.B;
    if( !iss ) At.B = 0;
    return At;
}

string GenerarAtr( vector<Atributo>& Atributos ) {
    string res;
    int tam = Atributos.size();
    for( int i = 0; i < tam; i++ ) {
        res.append( " " + Atributos[i].Nombre + " " );
        int valor = CalcAtr( Atributos[i] );
        ostringstream oss;
        oss << valor;
        res.append( oss.str() );
    }
    return res;
}

int CalcAtr( const Atributo& Attr ) {
    int Res = Attr.B;
    for( int i = 0; i < Attr.X; i++ ) {
        Dado = ( 75*Dado ) % 65537;
        Res += ( Dado % Attr.Y ) + 1;
    }
    if( Res <= 0 ) Res = 1;
    return Res;
}
