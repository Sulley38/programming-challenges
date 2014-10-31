#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iCasos;
    cin >> iCasos;
    while( iCasos-- ) {
        int iAsientos, iPreguntas;
        cin >> iAsientos >> iPreguntas;
        while( iPreguntas-- ) {
            int iEquipo;
            cin >> iEquipo;
            cout << iEquipo*iAsientos << " " << iEquipo*iAsientos+iAsientos-1 << endl;
        }
        if( iCasos > 0 ) cout << endl;
    }

    return 0;
}
