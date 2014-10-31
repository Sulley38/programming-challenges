#include <iostream>

using namespace std;

int main()
{
    int V1, V2, V3, W1, W2, W3;
    cin >> V1 >> V2 >> V3 >> W1 >> W2 >> W3;
    cout << V2*W3 - V3*W2 << " " << V3*W1 - V1*W3 << " " << V1*W2 - V2*W1 << endl;
    return 0;
}
