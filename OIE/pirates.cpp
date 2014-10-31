#include <iostream>
#include <string>

using namespace std;

int main()
{
    string entrada, salida;
    string letras = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";

    getline( cin, entrada );
    while( entrada != "end" )
    {
        for( unsigned int i = 0; i < entrada.length(); i++ )
        {
            if( letras.find( entrada[i] ) != string::npos )
            {
                salida.push_back( entrada[i] );
                salida.push_back( 'o' );
                salida.push_back( entrada[i] );
            }
            else
            {
                salida.push_back( entrada[i] );
            }
        }
        cout << salida << endl;
        salida.clear();
        entrada.clear();
        getline( cin, entrada );
    }

    return 0;
}
