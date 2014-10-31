#include <iostream>
#include <map>
#include <string>

using namespace std;
string Palindromear( const string& Entrada );

string Palindromear( const string& Entrada )
{
    map<char,int> mLetras;
    for( int i = 0; i < int(Entrada.length()); i++ ) {
        mLetras[Entrada[i]]++;
    }

    bool bImpar = false;
    char LetraCentral;
    for( int j = 0; j < 26; j++ ) {
        if( mLetras[j+'a'] % 2 ) {
            if( !bImpar ) {
                bImpar = true;
                LetraCentral = j + 'a';
            }
            else
                return "NINGUN PALINDROMO";
        }
    }

    string Palindromo;
    for( int k = 0; k < 26; k++ ) {
        int iLetrasToAdd = mLetras[k+'a'] / 2;
        while( iLetrasToAdd-- )
            Palindromo.push_back( k + 'a' );
    }
    int iLength = Palindromo.size();

    if( bImpar )
        Palindromo.push_back( LetraCentral );
    for( int i = 0; i < iLength; i++ )
        Palindromo.push_back( Palindromo[iLength-1-i] );

    return Palindromo;
}

int main()
{
    int iPalabras = 0;
    cin >> iPalabras;

    while( iPalabras-- ) {
        string Entrada, Salida;
        cin >> Entrada;
        Salida = Palindromear( Entrada );
        cout << Salida << endl;
    }

    return 0;
}
