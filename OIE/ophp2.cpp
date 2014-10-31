#include <cctype>
#include <iostream>

using namespace std;
// Devuelve el primer caracter no blanco de la cadena
char FirstChar( const string& s )
{
    int i = 0;
    while( s[i] == ' ' ) i++;
    return s[i];
}
// Asigna nil a las variables correctas y lo muestra por pantalla
void Parse( const string& s )
{
    int Index = 0, Tam = s.size();
    while( Index < Tam ) {
        if( s[Index] == '$' ) {
            int Long = 1;
            while( isalnum(s[Index+Long]) || s[Index+Long] == '_' ) Long++;
            if( Long > 1 ) cout << "nil";
            else cout << s[Index];
            Index += Long-1;
        } else {
            cout << s[Index];
        }
        Index++;
    }
    cout << endl;
}

int main()
{
    string s;
    while( getline(cin, s) ) if( FirstChar(s) != '#' ) Parse(s);
    return 0;
}
