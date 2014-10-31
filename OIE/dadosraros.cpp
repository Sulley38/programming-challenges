#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int casos;
    cin >> casos;
    while( casos-- ) {
        int semilla, tiradas, numcaras;
        cin >> semilla >> tiradas >> numcaras;

        vector<int> Caras( numcaras );
        for( int i = 0; i < numcaras; i++ )
            cin >> Caras[i];

        while( tiradas > 1 ) {
            semilla = ( 75*semilla ) % 65537;
            cout << Caras[( semilla % numcaras )] << ",";
            tiradas--;
        }
        cout << Caras[( ( ( 75*semilla ) % 65537 ) % numcaras )] << "." << endl;
    }

    return 0;
}

