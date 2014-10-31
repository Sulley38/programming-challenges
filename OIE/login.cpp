#include <cctype>
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while( N-- ) {
        string s;
        cin >> s;

        int i = 0, Tam = s.size();
        bool Correcto = true, Punto = false;
        while( i < Tam && (isalnum( s[i] ) || s[i] == '_') ) i++;
        if( i == Tam ) {
            cout << "LOGIN" << endl;
        } else {
            if( s[i] == '@' && i > 0 ) {
                i++;
                if( s[i] == '.' ) {
                    Correcto = false;
                    i = Tam;
                }

                for( ; i < Tam; ++i ) {
                    if( s[i] == '.' ) {
                        if( s[i-1] == '.' || i+1 == Tam) {
                            Correcto = false;
                            i = Tam;
                        }
                        Punto = true;
                    } else if( !isalnum( s[i] ) && s[i] != '_' ) {
                        Correcto = false;
                        i = Tam;
                    }
                }

                if( Correcto && Punto )
                    cout << "E-MAIL" << endl;
                else
                    cout << "NADA" << endl;
            } else {
                cout << "NADA" << endl;
            }
        }
    }

    return 0;
}
