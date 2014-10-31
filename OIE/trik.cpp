#include <iostream>

using namespace std;

int main()
{
    char c;
    int Pos = 1;
    while( cin >> c ) {
        if( c == 'A' && Pos == 1 ) Pos = 2;
        else if( c == 'A' && Pos == 2 ) Pos = 1;
        else if( c == 'B' && Pos == 2 ) Pos = 3;
        else if( c == 'B' && Pos == 3 ) Pos = 2;
        else if( c == 'C' && Pos == 1 ) Pos = 3;
        else if( c == 'C' && Pos == 3 ) Pos = 1;
    }
    cout << Pos << endl;
    return 0;
}
