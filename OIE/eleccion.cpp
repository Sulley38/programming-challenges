#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Casos, Tiradas, Num;
    cin >> Casos;
    while( Casos-- ) {
        cin >> Tiradas;
        vector<int> Res(6);
        while( Tiradas-- ) {
            cin >> Num;
            Res[Num-1]++;
        }

        int Max = 0;
        bool Empate = false;
        for( int i = 1; i < 6; ++i ) {
            if( Res[i] > Res[Max] ) {
                Max = i;
                Empate = false;
            } else if( Res[i] == Res[Max] ) {
                Empate = true;
            }
        }

        if( Empate ) cout << "?" << endl;
        else cout << Max+1 << endl;
    }

    return 0;
}
