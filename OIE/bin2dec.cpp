#include <iostream>

using namespace std;

string Sumar( const string& M, const string& N )
{
    int TM = M.size(), TN = N.size(), TR = max(TM,TN)+1;
    string R( TR, '0' );
    // Realiza la suma
    for( int i = 0; i < TR; ++i ) {
        if( i < TM ) R[TR-1-i] += M[TM-1-i]-'0';
        if( i < TN ) R[TR-1-i] += N[TN-1-i]-'0';
        if( R[TR-1-i] > '9' ) { // Computa la llevada
            R[TR-2-i] += (R[TR-1-i]-'0')/10;
            R[TR-1-i] = (R[TR-1-i]-'0')%10 + '0';
        }
    }
    // Puede que el primer espacio no fuera necesario
    if( R[0] == '0' ) R = R.erase(0,1);
    return R;
}

int main()
{
    string s;
    while( cin >> s ) {
        string Res = "0", Potencia = "1";
        int Tam = s.size();
        for( int i = Tam-1; i >= 0; --i ) {
            if( s[i]-'0' == 1 ) Res = Sumar(Res,Potencia);
            Potencia = Sumar(Potencia,Potencia); // Multiplica por 2 para elevar el grado
        }
        cout << Res << endl;
    }
    return 0;
}
