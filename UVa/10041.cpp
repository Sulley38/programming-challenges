#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Casos, Familiares, Casa, Res;
    cin >> Casos;
    while( Casos-- ) {
        cin >> Familiares;
        vector<int> Nums(Familiares);
        for( int i = 0; i < Familiares; ++i )
            cin >> Nums[i];
        sort( Nums.begin(), Nums.end() );
        // Busca la mediana
        Casa = Familiares / 2;
        // Distancia final
        Res = 0;
        for( int i = 0; i < Familiares; ++i )
            Res += abs( Nums[Casa] - Nums[i] );
        cout << Res << endl;
    }

    return 0;
}
