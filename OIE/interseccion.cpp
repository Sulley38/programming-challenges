#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iDimension, iCasos;
    cin >> iDimension >> iCasos;

    while( iCasos-- ) {
        int iObjetos;
        cin >> iObjetos;

        vector< vector<int> > Objeto( iObjetos, vector<int>( iDimension*2 ) );
        for( int a = 0; a < iObjetos; a++ ) {
            for( int i = 0; i < iDimension * 2; i++ ) {
                cin >> Objeto[a][i];
            }
        }

        vector<int> Resultante( iDimension*2 );
        for( int i = 0; i < iDimension * 2; i++ ) {
            int iMax = -500, iMin = 500;

            for( int a = 0; a < iObjetos; a++ ) {
                if( i < iDimension )
                    iMax = max( Objeto[a][i], iMax );
                else
                    iMin = min( Objeto[a][i], iMin );
            }

            if( i < iDimension ) {
                Resultante[i] = iMax;
            } else {
                Resultante[i] = iMin;
            }

        }

        int iResultado = 0;
        if( iDimension == 1 ) {
            iResultado = Resultante[1] - Resultante[0];
        } else if( iDimension == 2 ) {
            int iOp1 = Resultante[2] - Resultante[0], iOp2 = Resultante[3] - Resultante[1];
            if( iOp1 >= 0 && iOp2 >= 0 )
                iResultado = iOp1 * iOp2;
        } else {
            int iOp1 = Resultante[3] - Resultante[0], iOp2 = Resultante[4] - Resultante[1], iOp3 = Resultante[5] - Resultante[2];
            if( iOp1 >= 0 && iOp2 >= 0 && iOp3 >= 0 )
                iResultado = iOp1 * iOp2 * iOp3;
        }

        if( iResultado < 0 ) cout << "0" << endl;
        else cout << iResultado << endl;

    }

    return 0;
}
