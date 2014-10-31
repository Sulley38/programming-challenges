#include <iostream>

using namespace std;

int main()
{
    int iNumero = 0;
    cin >> iNumero;

    while( iNumero > 0 ) {
        cout << iNumero << "..." << endl;
        iNumero--;
    }
    cout << "IGNITION!" << endl;

    return 0;
}
