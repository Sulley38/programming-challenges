#include <iostream>

using namespace std;

int main()
{
    int N, Diag, Fact = 1, R = 0;
    cin >> N;
    Diag = N-3;
    for( int i = 0; i < N-3; i++ ) {
        for( int j = 1; j <= Diag; j++ ) R += Fact*j;
        Diag--;
        Fact++;
    }
    cout << R << endl;
    return 0;
}
