#include <iostream>

using namespace std;

int main()
{
    int iCasos, A, B, C, D;
    cin >> iCasos;
    while( iCasos-- ) {
        cin >> A >> B >> C >> D;
        if( C + B  == 0 && A + D == 0 ) cout << "ALL" << endl;
        else if( A + D == 0 ) cout << "NONE" << endl;
        else cout << ( C + B ) / (A + D) << endl;
    }

    return 0;
}
