#include <cmath>
#include <iostream>

using namespace std;

long long Decimal( const string& Numero )
{
    long long iRes = 0, iLength = Numero.size();

    for( int i = 0; i < iLength; i++ ) {
        if( Numero[i] >= 'A' && Numero[i] <= 'F' ) {
            iRes += ( Numero[i] - 55 )*pow( 16, iLength-i-1 );
        } else {
            iRes += ( Numero[i] - '0' )*pow( 16, iLength-i-1 );
        }
    }

    return iRes;
}

string Binario( long long Numero )
{
    string Bin, Res;

    if( Numero == 0 ) Bin.push_back( '0' );
    while( Numero > 0 ) {
        Bin.push_back( ( Numero % 2 ) + '0' );
        Numero /= 2;
    }

    for( string::iterator it = Bin.end()-1; it != Bin.begin()-1; it-- )
        Res.push_back( *it );

    return Res;
}

int main()
{
    string Entrada;
    while( cin >> Entrada ) {
        long long Dec = Decimal( Entrada );
        cout << Dec << " " << Binario( Dec ) << endl;
    }

    return 0;
}
