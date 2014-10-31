#include <iostream>

using namespace std;

int main()
{
    int iCantidad = 0;
    int vMonedas[8] = { 200, 100, 50, 20, 10, 5, 2, 1 };

    cin >> iCantidad;
    while( iCantidad > -1 ) {
        int iResto = iCantidad, iMonedas = 0;

        for( int i = 0; i < 8; i++ ) {
            iMonedas += iResto / vMonedas[i];
            iResto %= vMonedas[i];
        }

        cout << iCantidad << ": " << iMonedas << endl;
        cin >> iCantidad;
    }

    return 0;
}
