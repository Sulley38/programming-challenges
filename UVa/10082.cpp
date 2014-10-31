#include <iostream>

using namespace std;

int main()
{
    string Caracteres = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./", s;
    while( getline(cin,s) ) {
        for( int i = 0; i < int(s.size()); ++i ) {
            if( s[i] != ' ' ) {
                int Pos = Caracteres.find(s[i]);
                s[i] = Caracteres[Pos-1];
            }
        }
        cout << s << endl;
    }

    return 0;
}
