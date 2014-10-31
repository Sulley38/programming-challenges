#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> Dimensiones;

int main()
{
    Dimensiones Foto;
    while( cin >> Foto.first >> Foto.second ) {
        int iMarcos = 0, iAreaActual = 1000001;
        cin >> iMarcos;

        Dimensiones Marco;
        for( int i = 0; i < iMarcos; i++ ) {
            cin >> Marco.first >> Marco.second;
            if( Marco.first * Marco.second < iAreaActual && ((Marco.first >= Foto.first && Marco.second >= Foto.second) || (Marco.first >= Foto.second && Marco.second >= Foto.first)) )
                iAreaActual = Marco.first * Marco.second;
        }
        if( iAreaActual == 1000001 )
            iAreaActual = -1;
        cout << iAreaActual << endl;
    }
    return 0;
}
