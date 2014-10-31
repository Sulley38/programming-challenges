#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iCasos, iToma;
    cin >> iCasos;

    vector<long> Frys;
    Frys.push_back( 1 );
    Frys.push_back( 1 );
    while( iCasos-- ) {
        cin >> iToma;
        for( int i = Frys.size(); i < iToma+1; i++ )
                Frys.push_back( ( Frys[i-1] + Frys[i-2] ) % 1000000000 );

        cout << "Universo, Toma " << iToma << ": " << Frys[iToma] << " Philip J. Fry" << endl;
    }

    return 0;
}
