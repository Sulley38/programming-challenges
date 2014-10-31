#include <iostream>

using namespace std;
typedef pair<int,int> Bicho;

int main()
{
    Bicho A, B;
    int iGorros, iCalcetines, iBichosA, iBichosB;
    while( cin >> A.first >> A.second >> B.first >> B.second >> iGorros >> iCalcetines ) {
        iBichosB = (iGorros*A.second - iCalcetines*A.first)/( B.first*A.second - B.second*A.first);
        iBichosA = ( iGorros - B.first*iBichosB )/A.first;
        cout << iBichosA << " " << iBichosB << endl;
    }

    return 0;
}
