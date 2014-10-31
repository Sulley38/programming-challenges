#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iCasos, iTramos, iXTunel, iCambioSpeed;
    cin >> iCasos;
    while( iCasos-- ) {
        cin >> iTramos >> iXTunel >> iCambioSpeed;

        int iSuma = 0;
        vector<int> X( iTramos+1 ), Y( iTramos+1 );
        for( int i = 0; i < iTramos+1; i++ ) {
            cin >> X[i] >> Y[i];
            if( X[i] == iXTunel )
                iSuma = *max_element( Y.begin(), Y.end() ) * iCambioSpeed;
        }

        cout << iSuma << endl;
    }

    return 0;
}
