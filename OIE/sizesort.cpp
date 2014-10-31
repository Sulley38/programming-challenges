#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Ordenar( const string& a, const string& b )
{
    return a.size() < b.size();
}

int main()
{
    int Nombres;
    cin >> Nombres;
    cin.get();

    vector<string> vNames( Nombres );
    for( int i = 0; i < Nombres; i++ )
        getline( cin, vNames[i] );

    stable_sort( vNames.begin(), vNames.end(), Ordenar );

    for( int i = 0; i < Nombres; i++ )
        cout << vNames[i] << endl;

    return 0;
}
