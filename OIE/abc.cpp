#include <iostream>

using namespace std;

int main()
{
    int i[3], x=0, A, B, C;
    char c[3];
    cin >> i[0] >> i[1] >> i[2] >> c[0] >> c[1] >> c[2];

    A = min( i[0], min( i[1], i[2] ) );
    C = max( i[0], max( i[1], i[2] ) );
    if( i[0] != A && i[0] != C ) B = i[0];
    else if( i[1] != A && i[1] != C ) B = i[1];
    else B = i[2];

    while( x < 3 ) {
        if( c[x] == 'A' ) cout << A;
        else if( c[x] == 'B' ) cout << B;
        else if( c[x] == 'C' ) cout << C;
        if( x<2 ) cout << " ";
        x++;
    }
    cout << endl;
    return 0;
}
