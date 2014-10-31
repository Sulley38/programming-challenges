#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    double r;
    cin >> r;

    cout << r*r*M_PI << endl << r*r*2 << endl;

    return 0;
}
