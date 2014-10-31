#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int iColumnas, iFilas;

    while( cin >> iFilas >> iColumnas ) {
        vector< vector<char> > sopa( iFilas+2, vector<char>(iColumnas+2) );
        int iCoincidencias = 0;

        for( int i = 1; i < iFilas+1; i++ ) {
            for( int j = 1; j < iColumnas+1; j++ ) {
                cin >> sopa[i][j];
            }
        }

        for( int i = 1; i < iFilas+1; i++ ) {
            for( int j = 1; j < iColumnas+1; j++ ) {
                if( sopa[i][j] == 'O' ){
                    if( sopa[i][j+1] == 'I' )
                        if( sopa[i][j+2] == 'E' )
                            iCoincidencias++;
                    if( sopa[i][j-1] == 'I' )
                        if( sopa[i][j-2] == 'E' )
                            iCoincidencias++;
                    if( sopa[i+1][j] == 'I' )
                        if( sopa[i+2][j] == 'E' )
                            iCoincidencias++;
                    if( sopa[i-1][j] == 'I' )
                        if( sopa[i-2][j] == 'E' )
                            iCoincidencias++;
                    if( sopa[i+1][j+1] == 'I' )
                        if( sopa[i+2][j+2] == 'E' )
                            iCoincidencias++;
                    if( sopa[i+1][j-1] == 'I' )
                        if( sopa[i+2][j-2] == 'E' )
                            iCoincidencias++;
                    if( sopa[i-1][j+1] == 'I' )
                        if( sopa[i-2][j+2] == 'E' )
                            iCoincidencias++;
                    if( sopa[i-1][j-1] == 'I' )
                        if( sopa[i-2][j-2] == 'E' )
                            iCoincidencias++;
                }
            }
        }
        cout << iCoincidencias << endl;
    }

    return 0;
}
