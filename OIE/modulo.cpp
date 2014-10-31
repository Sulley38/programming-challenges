#include <iostream>
#include <map>

using namespace std;

int main()
{
    int e, res = 0;
    map<int,int> Rep;
    for( int i = 0; i < 10; i++ ) {
        cin >> e;
        if( Rep[e%42] == 0 ) {
            Rep[e%42] = 1;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
