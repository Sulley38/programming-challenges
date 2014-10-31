#include <iostream>

using namespace std;
typedef long long ll;

ll mcd( ll A, ll B )
{
    if( B == 0 ) return A;
    else return mcd( B, A%B );
}

int main()
{
    ll a, b;
    while( cin >> a >> b ) cout << mcd(a,b) << endl;
    return 0;
}
