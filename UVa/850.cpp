#include <iostream>
#include <vector>

using namespace std;
const string Ref = "the quick brown fox jumps over the lazy dog";

bool Match( const string& S, vector<char>& E )
{
    int Tam = S.size();
    if( Tam != 43 ) return false; // No encaja en tamanyo
    // Comprobar si puede coincidir
    for( int i = 0; i < 43; ++i ) {
        if( Ref[i] != ' ' ) {
            if( E[S[i]-'a'] == '*' )
                E[S[i]-'a'] = Ref[i];
            else if( E[S[i]-'a'] != Ref[i] )
                return false;
        }
    }
    return true;
}

int main()
{
    int Casos;
    cin >> Casos;
    cin.ignore(2);
    while( Casos-- ) {
        vector<string> Frases;
        vector<char> Equivalencia(26,'*');
        string Linea;
        while( getline(cin,Linea) && Linea != "" ) {
            Frases.push_back(Linea);
            if( Equivalencia[0] == '*' ) {
                // Intentar establecer la equivalencia
                if( !Match(Linea,Equivalencia) ) {
                    Equivalencia.clear();
                    Equivalencia.resize(26,'*');
                }
            }
        }

        if( Equivalencia[0] == '*' ) {
            cout << "No solution." << endl;
        } else {
            for( int i = 0; i < int(Frases.size()); ++i ) {
                for( int j = 0; j < int(Frases[i].size()); ++j ) {
                    if( Frases[i][j] == ' ' ) cout << ' ';
                    else cout << Equivalencia[Frases[i][j]-'a'];
                }
                cout << endl;
            }
        }
        if( Casos > 0 ) cout << endl;
    }

    return 0;
}
