#include <iostream>

using namespace std;

void Parse( const string& s )
{
    int Index = 0, Tam = s.size(), Long;
    string Current;
    while( Index < Tam ) {
        // Variable
        if( s[Index] == '$' ) {
            if( Current != "" ) cout << " ";
            Current = "VAR";
            Long = 1;
            while( isalnum(s[Index+Long]) || s[Index+Long] == '_' ) Long++;
            if( Long == 1 ) {
                cout << "ERROR" << endl;
                return;
            }
            Index += Long;
            cout << Current;
        }
        // Numero
        else if( isdigit(s[Index]) ) {
            if( Current != "" ) cout << " ";
            Current = "NUM";
            Long = 1;
            while( isdigit(s[Index+Long]) ) Long++;
            Index += Long;
            cout << Current;
        }
        // Adicion
        else if( s[Index] == '+' || s[Index] == '-' ) {
            if( Current != "" ) cout << " ";
            Current = "OP+";
            Index++;
            cout << Current;
        }
        // Multiplicacion
        else if( s[Index] == '*' || s[Index] == '/' || s[Index] == '%' ) {
            if( Current != "" ) cout << " ";
            Current = "OP*";
            Index++;
            cout << Current;
        }
        // Simbolos
        else if( s[Index] == '(' || s[Index] == ')' || s[Index] == '=' ) {
            if( Current != "" ) cout << " ";
            Current.assign(1,s[Index]);
            Index++;
            cout << Current;
        }
        // Espacio
        else if( s[Index] == ' ' ) {
            Index++;
        }
        // Otro: error
        else {
            if( Current != "" ) cout << " ";
            cout << "ERROR" << endl;
            return;
        }
    }
    cout << endl;
}

int main()
{
    string s;
    while( getline(cin, s) ) Parse(s);
    return 0;
}
