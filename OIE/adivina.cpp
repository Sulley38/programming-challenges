#include <iostream>

using namespace std;

int main()
{
    int n, res = 100;
    while( cin >> n )
        res -= n;
    cout << res << endl;

    return 0;
}

