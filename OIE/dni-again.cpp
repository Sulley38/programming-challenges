#include <iostream>
#include <sstream>
#include <string>

using namespace std;
string GetDigitoControl( const string& Campo );

string GetDigitoControl( const string& Campo )
{
    int iDigito = 0, iSuma = 0;

    for( int i = 1; i < int(Campo.size())+1; i++ ) {
        if( isalpha( Campo[i-1] ) )
            iDigito = Campo[i-1]-'A';
        else
            iDigito = Campo[i-1]-'0';

        if( i % 3 == 1 )
            iSuma += iDigito*7;
        else if( i % 3 == 2 )
            iSuma += iDigito*3;
        else
            iSuma += iDigito;
    }

    ostringstream oss;
    oss << iSuma;
    string sSuma = oss.str();
    string sDigito( sSuma, sSuma.length()-1, 1 );

    return sDigito;
}

int main()
{
    string sNumero, sFechaNac, sFechaCad;
    while ( cin >> sNumero >> sFechaNac >> sFechaCad ) {
        string DC4, DC7, DC10, DC13;

        DC4 = GetDigitoControl( sNumero );
        DC7 = GetDigitoControl( sFechaNac );
        DC10 = GetDigitoControl( sFechaCad );
        DC13 = GetDigitoControl( sNumero + DC4 + sFechaNac + DC7 + sFechaCad + DC10 );

        cout << DC13 << endl;
    }

    return 0;
}
