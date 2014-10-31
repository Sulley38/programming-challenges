#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Carton;
typedef vector<int> Situacion;
typedef pair<int,int> Turnos;

Carton GetCarton();
Situacion GetSituacion();
Turnos GetTurnos( Carton vCarton, const vector<int>& vBombo );

Carton GetCarton()
{
    int iNumero = 0;
    Carton vCarton( 3, vector<int>(5) );
    for( int i = 0; i < 3; i++ ) {
        for( int j = 0; j < 5; j++ ) {
            cin >> iNumero;
            vCarton[i][j] = iNumero;
        }
    }
    return vCarton;
}

Situacion GetSituacion()
{
    int iCarton = 0, iNumero = 0;
    Situacion vSituacion;
    cin >> iNumero;
    for( int i = 0; i < iNumero; i++ ) {
        cin >> iCarton;
        vSituacion.push_back( iCarton );
    }
    return vSituacion;
}

Turnos GetTurnos( Carton vCarton, const vector<int>& vBombo )
{
    Turnos pTurnos;
    bool bLinea = false;
    int iNumerosTachados[3] = { 0, 0, 0 };
    int iNumerosRestantes = 15;

    for( int i = 0; i < 99; i++ ) {
        for( int a = 0; a < 3; a++ ) {
            for( int b = 0; b < 5; b++ ) {
                if( vBombo[i] == vCarton[a][b] ) {
                    iNumerosTachados[a]++;
                    iNumerosRestantes--;
                }
                if( !bLinea && iNumerosTachados[a] == 5 ) {
                    pTurnos.first = i+1;
                    bLinea = true;
                }
                if( iNumerosRestantes == 0 ) {
                    pTurnos.second = i+1;
                    i = 99; a = 3; b = 5;
                }
            }
        }
    }

    return pTurnos;
}

int main()
{
    int iCartones = 0;
    cin >> iCartones;
    vector<Carton> vCartones( iCartones, Carton( 3, vector<int>(5) ) );
    for( int i = 0; i < iCartones; i++ ) {
        vCartones[i] = GetCarton();
    }

    int iSituaciones = 0;
    cin >> iSituaciones;
    vector<Situacion> vSituaciones( iSituaciones, vector<int>(0) );
    for( int i = 0; i < iSituaciones; i++ ) {
        vSituaciones[i] = GetSituacion();
    }

    int iBola = 0;
    vector<int> vBombo( 99 );
    for( int i = 0; i < 99; i++ ) {
        cin >> iBola;
        vBombo[i] = iBola;
    }

    vector< Turnos > vTurnos( iCartones );
    for( int i = 0; i < iCartones; i++ ) {
        vTurnos[i] = GetTurnos( vCartones[i], vBombo );
    }

    for( int i = 0; i < iSituaciones; i++ ) {
        int iLinea = 0, iBingo = 0, iTurnoL = 100, iTurnoB = 100;
        for( int j = 0; j < int(vSituaciones[i].size()); j++ ) {
            if( vTurnos[ vSituaciones[i][j]-1 ].first < iTurnoL ) {
                iLinea = vSituaciones[i][j];
                iTurnoL = vTurnos[ vSituaciones[i][j]-1 ].first;
            } else if( vTurnos[ vSituaciones[i][j]-1 ].first == iTurnoL ) {
                iLinea = 0;
            }
            if( vTurnos[ vSituaciones[i][j]-1 ].second < iTurnoB ) {
                iBingo = vSituaciones[i][j];
                iTurnoB = vTurnos[ vSituaciones[i][j]-1 ].second;
            } else if( vTurnos[ vSituaciones[i][j]-1 ].second == iTurnoB ) {
                iBingo = 0;
            }
        }
        cout << iLinea << " " << iBingo << endl;
    }

    return 0;
}
