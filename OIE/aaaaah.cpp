#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iRadio = 0;
    string letras;

    cin >> iRadio;
    iRadio = iRadio * 4;
    while( iRadio-- )
        letras.push_back( 'a' );

    cout << "A" << letras << "h" << endl;
    return 0;
}

