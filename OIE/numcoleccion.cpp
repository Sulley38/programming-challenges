#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pNumeros;
    char cAccion;

    while( cin >> cAccion ) {
        int iNumero = 0, iRestar = 0, iSumar = 0;

        if( cAccion == 'G' ) {
            cin >> iNumero;
            pNumeros.push( iNumero );
        } else if( cAccion == 'C' ) {
            if( !pNumeros.empty() ) {
                iNumero = pNumeros.top();
                cout << iNumero << endl;
            } else {
                cout << "error: no hay elementos" << endl;
            }
        } else if( cAccion == 'E' ) {
            if( !pNumeros.empty() ) {
                pNumeros.pop();
            } else {
                cout << "error: no hay elementos" << endl;
            }
        } else if( cAccion == 'I' ) {
            if( !pNumeros.empty() ) {
                iNumero = pNumeros.top();
                cin >> iSumar;
                pNumeros.pop();
                pNumeros.push( iNumero + iSumar );
            } else {
                cout << "error: no hay elementos" << endl;
            }
        } else if( cAccion == 'D' ) {
            if( !pNumeros.empty() ) {
                iNumero = pNumeros.top();
                cin >> iRestar;
                pNumeros.pop();
                pNumeros.push( iNumero - iRestar );
            } else {
                cout << "error: no hay elementos" << endl;
            }
        }

    }

    return 0;
}
