#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iSegundos, iCanciones;
    while( cin >> iSegundos >> iCanciones ) {

        vector<int> vDuraciones( iCanciones );
        for( int i = 0; i < iCanciones; i++ )
            cin >> vDuraciones[i];
        sort( vDuraciones.begin(), vDuraciones.end() );

        int Index = 0;
        while( iSegundos > 0 && Index < iCanciones && vDuraciones[Index] <= iSegundos ) {
            iSegundos -= vDuraciones[Index];
            Index++;
            if( iSegundos > 0 )
                iSegundos--;
        }

        cout << Index << endl;
    }

    return 0;
}
