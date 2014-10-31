#include <iostream>
#include <string>

using namespace std;

int main()
{
    int iValor = 0, j = 0;
    char Entrada;
    string Valor[8] = { " \n", "ae", "os", "dinr", "cltu", "mp", "bfghjqvxyz", "kw" };

    while( cin >> Entrada ) {
        while( Valor[j].find( Entrada ) == string::npos ) { j++; }
        iValor += j;
        j = 0;
    }

    cout << iValor << endl;
    return 0;
}

