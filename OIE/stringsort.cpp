#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Nombres;
    cin >> Nombres;
    cin.get();

    vector<string> vNames( Nombres );
    for( int i = 0; i < Nombres; i++ )
        getline( cin, vNames[i] );

    sort( vNames.begin(), vNames.end() );

    for( int i = 0; i < Nombres; i++ )
        cout << vNames[i] << endl;

    return 0;
}
