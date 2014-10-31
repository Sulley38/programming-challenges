#include <iostream>
#include <vector>

using namespace std;

void LeerEntrada( vector< vector<char> >& T )
{
    string s;
    for( int i = 0; i < 8; ++i ) {
        cin >> s;
        s[0] -= 'A';
        s[1] -= '0';
        if( i == 0 ) { // Portaaviones
            if( s[2] == 'h') {
                T[s[0]][s[1]] = 'X';
                T[s[0]][s[1]+1] = 'X';
                T[s[0]][s[1]+2] = 'X';
                T[s[0]][s[1]+3] = 'X';
                T[s[0]][s[1]+4] = 'X';
            } else {
                T[s[0]][s[1]] = 'X';
                T[s[0]+1][s[1]] = 'X';
                T[s[0]+2][s[1]] = 'X';
                T[s[0]+3][s[1]] = 'X';
                T[s[0]+4][s[1]] = 'X';
            }
        } else if( i == 1 || i == 2 ) { // Acorazados
            if( s[2] == 'h') {
                T[s[0]][s[1]] = 'X';
                T[s[0]][s[1]+1] = 'X';
                T[s[0]][s[1]+2] = 'X';
                T[s[0]][s[1]+3] = 'X';
            } else {
                T[s[0]][s[1]] = 'X';
                T[s[0]+1][s[1]] = 'X';
                T[s[0]+2][s[1]] = 'X';
                T[s[0]+3][s[1]] = 'X';
            }
        } else if( i == 3 || i == 4 || i == 5 ) { // Destructores
            if( s[2] == 'h') {
                T[s[0]][s[1]] = 'X';
                T[s[0]][s[1]+1] = 'X';
                T[s[0]][s[1]+2] = 'X';
            } else {
                T[s[0]][s[1]] = 'X';
                T[s[0]+1][s[1]] = 'X';
                T[s[0]+2][s[1]] = 'X';
            }
        } else if( i == 6 || i == 7 ) { // Submarinos
            if( s[2] == 'h') {
                T[s[0]][s[1]] = 'X';
                T[s[0]][s[1]+1] = 'X';
            } else {
                T[s[0]][s[1]] = 'X';
                T[s[0]+1][s[1]] = 'X';
            }
        }

    }
}

int main()
{
    vector< vector<char> > Tablero( 10, vector<char>(10,'=') );
    vector< vector<bool> > Atacado( 10, vector<bool>(10,false) );
    // Situar los barcos
    LeerEntrada( Tablero );
    // Atacar
    cin.ignore(1);
    string s;
    while( getline( cin,s) ) {
        for( int i = 0; i < int(s.size()); i += 3 )
            Atacado[s[i]-'A'][s[i+1]-'0'] = true;

        cout << " 0123456789" << endl;
        for( int i = 0; i < 10; ++i ) {
            cout << char(i+'A');
            for( int j = 0; j < 10; ++j ) {
                if( Atacado[i][j] )
                    cout << Tablero[i][j];
                else
                    cout << ".";
            }
            cout << endl;
        }
        cout << "-----------" << endl;
    }

    return 0;
}
