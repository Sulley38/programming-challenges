#include <iostream>

using namespace std;

int main()
{
    int Semilla;
    cin >> Semilla;

    for( int i = 0; i < 10; i++ ) {
        Semilla = ( 13821*Semilla ) % 32768;
        cout << Semilla << ": " << Semilla%7+1 << endl;
    }

    return 0;
}
