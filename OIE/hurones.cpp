#include <iostream>

using namespace std;

int main()
{
    int k, n, res = 0, buffer = 0;
    cin >> k >> n;

    for( int i = 0; i < k; i++ ) {
        cin >> buffer;
        res += buffer / n;
    }

    cout << res << endl;

    return 0;
}

