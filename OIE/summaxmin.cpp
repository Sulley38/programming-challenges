#include <iostream>

using namespace std;

int main()
{
    int iNumero = 0, iMenor = 2147483640, iMayor = -2147483640;

    while( cin >> iNumero ) {
        if( iNumero < iMenor )
            iMenor = iNumero;
        if( iNumero > iMayor )
            iMayor = iNumero;
    }

    cout << iMenor + iMayor << endl;
    return 0;
}

