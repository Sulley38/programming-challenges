#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<string,int> Nombres;
    string s;
    int Res = 0;
    for( int i = 0; i < N; ++i ) {
        cin >> s;
        Nombres[s]++;
        int Cuenta = 0;
        for( map<string,int>::iterator it = Nombres.begin(); it != Nombres.end(); ++it )
            if( it->first != s )
                Cuenta += it->second;
        if( Nombres[s]-1 > Cuenta )
            Res++;
    }

    cout << Res << endl;

    return 0;
}
