#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    int p1 = 0, p2 = 0;
    while( cin >> s1 >> s2 ) {
        if( s1 == "piedra" ) {
            if( s2 == "papel" ) p2 += 2;
            else if( s2 == "piedra" ) { p1++; p2++; }
            else p1 += 2;
        } else if( s1 == "papel" ) {
            if( s2 == "tijeras" ) p2 += 2;
            else if( s2 == "papel" ) { p1++; p2++; }
            else p1 += 2;
        } else {
            if( s2 == "piedra" ) p2 += 2;
            else if( s2 == "tijeras" ) { p1++; p2++; }
            else p1 += 2;
        }
    }

    cout << p1 << " " << p2 << endl;
    return 0;
}
