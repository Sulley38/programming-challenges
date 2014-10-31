#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    while( cin >> x1 >> y1 >> x2 >> y2 ) {
        int Pasos = 0;

        if( x1 < x2 ) {
            Pasos += x2 - x1;
        } else if( x1 > x2 ) {
            Pasos += x1 - x2;
        } else {
            if( x1 % 2 == 0 && y1 != y2 ) Pasos += 2;
        }
        if( y1 < y2 ) {
            Pasos += y2 - y1;
        } else if( y1 > y2 ) {
            Pasos += y1 - y2;
        } else {
            if( y1 % 2 == 0 && x1 != x2 ) Pasos += 2;
        }

        cout << Pasos << endl;
    }

    return 0;
}


