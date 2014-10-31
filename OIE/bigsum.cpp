#include <iostream>
#include <string>

using namespace std;

string Suma( const string& M, const string& N )
{
    int TM = M.size(), TN = N.size(), TR = max(TM,TN)+1;
    string R( TR, 0 );
    // Realiza la suma
    for( int i = 0; i < TR; ++i ) {
        if( i < TM ) R[TR-1-i] += M[TM-1-i]-'0';
        if( i < TN ) R[TR-1-i] += N[TN-1-i]-'0';
        if( R[TR-1-i] > 9 ) { R[TR-2-i] += R[TR-1-i]/10; R[TR-1-i] %= 10; } // Computa la llevada
    }
    // Convierte en string
    for( int i = 0; i < TR; ++i ) R[i] += '0';
    // Puede que el primer espacio no fuera necesario
    if( R[0] == '0' ) R = R.erase(0,1);
    return R;
}

int main()
{
    string a, b;
    while( cin >> a >> b ) cout << a << "+" << b << "=" << Suma(a,b) << endl;
    return 0;
}
