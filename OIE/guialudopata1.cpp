#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    double R, D, F;
    while( cin >> R >> D >> F )
        cout << ( D*2*R/100 + F*250/100 )/R << endl;
    return 0;
}
