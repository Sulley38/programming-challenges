#include <iostream>

using namespace std;

int main()
{
    int iIngredientes, iQueso, iCoste = 0;
    char Tam;
    cin >> Tam >> iIngredientes >> iQueso;
    if( Tam == 'M' )
        iCoste = 4 + iIngredientes*1 + iQueso*2;
    else
        iCoste = 9 + iIngredientes*2 + iQueso*3;

    cout << iCoste << endl;
    return 0;
}
