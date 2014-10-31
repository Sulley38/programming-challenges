#include <iostream>

using namespace std;

int main()
{
    string Traduccion, Texto;
    while( cin >> Traduccion ) {
        int iLineas = 0, iPos = 0;

        cin >> iLineas;
        for( int i = 0; i < iLineas; i++ ) {
            cin >> Texto;
            for( int j = 0; j < int(Texto.size()); j++ ) {
                if( Texto[j] == '_' ) {
                    Texto[j] = ' ';
                } else {
                    iPos = Traduccion.find( Texto[j] );
                    Texto[j] = iPos + 'a';
                }
            }
            cout << Texto << endl;
        }
        cout << endl;
    }

    return 0;
}
