#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> Coeficientes(6);
    int S2 = 0, S1 = 0, S0 = 0, A, B, C, Disc;
    while( cin >> Coeficientes[0] >> Coeficientes[1] >> Coeficientes[2] >> Coeficientes[3] >> Coeficientes[4] >> Coeficientes[5] ) {
        A = Coeficientes[0] - Coeficientes[3];
        B = Coeficientes[1] + Coeficientes[3]*Coeficientes[4] + Coeficientes[3]*Coeficientes[5];
        C = Coeficientes[2] - Coeficientes[3]*Coeficientes[4]*Coeficientes[5];
        if( A == 0 && B == 0 ) {
            if( C != 0 ) S0++;
        } else if( A == 0 ) {
            S1++;
        } else {
            Disc = B*B - 4*A*C;
            if( Disc < 0 ) S0++;
            else if( Disc > 0 ) S2++;
            else S1++;
        }
    }
    cout << S2 << " " << S1 << " " << S0 << endl;

    return 0;
}

