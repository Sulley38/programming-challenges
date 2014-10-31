#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<int> > Matriz;
void EscribirMatriz( const Matriz& M );

void EscribirMatriz( const Matriz& M )
{
    int iSize = M.size(), iRowSize = M[0].size();
    for( int i = 0; i < iSize; i++ ) {
        cout << "[";
        for( int j = 0; j < iRowSize; j++ ) {
            cout << M[i][j];
            if( j < iRowSize-1 )
                cout << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    int iFilas = 0, iColumnas = 0;
    cin >> iFilas >> iColumnas;
    Matriz mEjercicio( iFilas, vector<int>( iColumnas ) );

    for( int i = 0; i < iFilas; i++ ) {
        for( int j = 0; j < iColumnas; j++ ) {
            cin >> mEjercicio[i][j];
        }
    }
    EscribirMatriz( mEjercicio );

    string Orden;
    while( cin >> Orden ) {
        cout << endl;
        if( Orden == "SWAPROW" ) {
            int iFila1, iFila2;
            cin >> iFila1 >> iFila2;
            mEjercicio[iFila1-1].swap( mEjercicio[iFila2-1] );
            EscribirMatriz( mEjercicio );
        } else if( Orden == "SWAPCOL" ) {
            int iColumna1, iColumna2;
            cin >> iColumna1 >> iColumna2;
            for( int i = 0; i < iFilas; i++ ) {
                for( int j = 0; j < iColumnas; j++ ) {
                    if( j == iColumna1-1 ){
                        swap( mEjercicio[i][j], mEjercicio[i][iColumna2-1] );
                    }
                }
            }
            EscribirMatriz( mEjercicio );
        } else if( Orden == "MULROW" ) {
            int iFila, iNumero;
            cin >> iFila >> iNumero;
            for( int j = 0; j < iColumnas; j++ ) {
                mEjercicio[iFila-1][j] *= iNumero;
            }
            EscribirMatriz( mEjercicio );
        } else {
            int iFila1, iFila2, iNumero;
            cin >> iFila1 >> iFila2 >> iNumero;
            for( int j = 0; j < iColumnas; j++ ) {
                mEjercicio[iFila1-1][j] += mEjercicio[iFila2-1][j]*iNumero;
            }
            EscribirMatriz( mEjercicio );
        }
    }

    cout << "." << endl;
    return 0;
}
