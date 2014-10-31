#include <iostream>

using namespace std;

int main()
{
    int iPosicion, X, Y;
    cin >> iPosicion >> X >> Y;
    while( iPosicion != 0 || X != 0 || Y != 0 ) {
        int iEnergia = 0;
        while( iPosicion > 1 ) {
            if( iPosicion % 2 == 0 && Y/(iPosicion/2) < X ) {
                iEnergia += Y;
                iPosicion /= 2;
            } else {
                iEnergia += X;
                iPosicion--;
            }
        }
        cout << iEnergia << endl;
        cin >> iPosicion >> X >> Y;
    }

    return 0;
}
