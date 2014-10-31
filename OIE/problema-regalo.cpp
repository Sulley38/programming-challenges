#include <iostream>

using namespace std;

int main()
{
    int iFilas = 0, iColumnas = 0;
    string estampado = "OIE";
    cin >> iFilas >> iColumnas;

    for( int i = 0; i < iFilas; i++ ) {
        for( int j = 0; j < iColumnas; j++ ) {
            cout << estampado[(i+j)%3];
        }
        cout << endl;
    }

    return 0;
}
