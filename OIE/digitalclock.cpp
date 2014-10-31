#include <iostream>
#include <map>
#include <string>

using namespace std;

void Avanzar( string& s ) {
    if( s[4] == '9' ) {
        s[4] = '0';
        if( s[3] == '5' ) {
            s[3] = '0';
            if( s[1] == '9' || (s[1] == '3' && s[0] == '2') ) {
                s[1] = '0';
                if( s[0] == '2' ) s[0] = '0';
                else s[0]++;
            } else {
                s[1]++;
            }
        } else {
            s[3]++;
        }
    } else {
        s[4]++;
    }
}

string HacerPalabra( const string& s, const string& Modo ) {
    string res( s );
    res.erase( 2, 1 );
    for( int i = 0; i <= 3; ++i ) {
        if( res[i] == '0' ) res[i] = 'O';
        else if( res[i] == '1' ) res[i] = 'I';
        else if( Modo == "UPSIDEDOWN" && res[i] == '3' ) res[i] = 'E';
        else if( Modo == "UPSIDEDOWN" && res[i] == '4' ) res[i] = 'H';
        else if( res[i] == '5' ) res[i] = 'S';
        else if( Modo == "UPSIDEDOWN" && res[i] == '7' ) res[i] = 'L';
        else return "";
    }
    if( Modo == "STD" ) return res;
    else return string( res.rbegin(), res.rend() );
}

int main()
{
    string t, s, e, pal;
    cin >> t >> s >> e;

    map<string,bool> Palabras;
    // Comprueba la hora inicial en busca de letras
    pal = HacerPalabra( s, t );
    if( pal != "" ) Palabras[pal] = true;
    while( s != e ) {
        // Avanza el reloj un minuto
        Avanzar( s );
        // Comprueba la hora en busca de letras
        pal = HacerPalabra( s, t );
        if( pal != "" ) Palabras[pal] = true;
    }

    for( map<string,bool>::iterator it = Palabras.begin(); it != Palabras.end(); it++ )
        cout << it->first << endl;

    return 0;
}
