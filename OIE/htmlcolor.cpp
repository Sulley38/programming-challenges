#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string Entrada;

    while( cin >> Entrada ) {

        if( Entrada == "NORMAL" ) {
            int R, G, B;
            char buffer[8];
            cin >> R >> G >> B;
            snprintf( buffer, 8, "#%02x%02x%02x", R, G, B );
            cout << buffer << endl;
        } else {
            int R, G, B;
            string HTML, Rs, Gs ,Bs;
            cin >> HTML;
            Rs.append( HTML, 1, 2 );
            Gs.append( HTML, 3, 2 );
            Bs.append( HTML, 5, 2 );
            sscanf( Rs.c_str(), "%x", &R );
            sscanf( Gs.c_str(), "%x", &G );
            sscanf( Bs.c_str(), "%x", &B );
            cout << R << " " << G << " " << B << endl;
        }

    }

    return 0;
}
