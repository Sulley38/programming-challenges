#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iNumeroDNI, iLetra;
    char X;
    string letras = "TRWAGMYFPDXBNJZSQVHLCKE";

    while( cin >> X >> iNumeroDNI )
    {
        if( X != 'X' )
            iNumeroDNI += (X-48)*10000000;
        iLetra = iNumeroDNI % 23;
        cout << letras[iLetra] << endl;
    }

    return 0;
}
