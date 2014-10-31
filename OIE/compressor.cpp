#include <iostream>
#include <string>

using namespace std;

string BuscarRepetida( const string& Cadena )
{
    int iOrgLength = Cadena.length(), iLength = Cadena.length()/2;
    string Repetido;

    while( iLength > 0 && Repetido == "" ) {
        int i = 0;
        while( i < iOrgLength && Repetido == "" ) {
            if( Cadena.find( Cadena.substr( i, iLength ), i + iLength ) != string::npos )
                    Repetido = Cadena.substr( i, iLength );
            i++;
        }
        iLength--;
    }

    return Repetido;
}

int main()
{
    string s;
    while( getline( cin, s ) )
        cout << BuscarRepetida(s) << endl;
    return 0;
}
