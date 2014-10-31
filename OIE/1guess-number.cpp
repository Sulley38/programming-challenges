#include <iostream>

using namespace std;

int main()
{
    int iNumero;
    while( cin >> iNumero ) {
        int Intentos = 1;
        while( iNumero > 1 ) {
            iNumero /= 2;
            Intentos++;
        }
        cout << Intentos << endl;
    }

    return 0;
}
