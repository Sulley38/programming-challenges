#include <cmath>
#include <iostream>

using namespace std;
typedef long long int lint;

int main()
{
    lint a, b, c, d, n;
    while( cin >> a >> b >> c >> d >> n ) {
        lint Res = a*n*n*n + b*n*n + c*n;
        int Up = n, Down = 0;
        while( Res != d ) {
            if( Res > d ) {
                Up = n;
                n -= (Up - Down)/2;
            } else {
                Down = n;
                n += (Up - Down)/2;
            }
            Res = a*n*n*n + b*n*n + c*n;
        }
        cout << int(n) << endl;
    }

    return 0;
}
