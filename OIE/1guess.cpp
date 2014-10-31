#include <iostream>

using namespace std;

int main()
{
    int iCasos = 0;
    cin >> iCasos;

    for( int i = 0; i < iCasos; i++ ) {
        int iLimMax = 501, iLimMin = 0, iNumero = 0;
        char c;

        for( int j = 0; j < 9; j++ ) {
            cin >> iNumero >> c;
            if( c == '+' && iLimMin < iNumero )
                iLimMin = iNumero;
            else if( c == '-' && iLimMax > iNumero )
                iLimMax = iNumero;
        }

        if( iLimMax - iLimMin == 2 )
            cout << iLimMax - 1 << endl;
        else
            cout << "?" << endl;
    }

    return 0;
}
