#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int largo, start, kilos = 0;
    cin >> largo >> start;
    vector<string> Pasillo( largo );
    for( int i = 0; i < largo; i++ ) cin >> Pasillo[i];

    int pos = start;
    while( pos < largo && Pasillo[pos][0] >= '0' && Pasillo[pos][0] <= '9' ) {
        kilos += Pasillo[pos][0] - '0';
        pos++;
    }
    pos = start - 1;
    while( pos >= 0 && Pasillo[pos][0] >= '0' && Pasillo[pos][0] <= '9' ) {
        kilos += Pasillo[pos][0] - '0';
        pos--;
    }

    cout << kilos << endl;

    return 0;
}
