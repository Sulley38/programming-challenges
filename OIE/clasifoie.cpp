#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int iConcursantes, iProblemas, iEnvios;
    cin >> iConcursantes >> iProblemas >> iEnvios;

    vector< map<int,int> > Concursantes( iConcursantes );
    while( iEnvios-- ) {
        int iConc, iProb, iPunt;
        cin >> iConc >> iProb >> iPunt;
        if( Concursantes[iConc][iProb] < iPunt )
            Concursantes[iConc][iProb] = iPunt;
    }

    pair<int,int> Ganador;
    for( int i = 0; i < iConcursantes; i++ ) {
        int iRecuento = 0;
        for( int j = 0; j < iProblemas; j++ ) {
            iRecuento += Concursantes[i][j];
        }

        if( iRecuento > Ganador.first ) {
            Ganador.first = iRecuento;
            Ganador.second = i;
        } else if( iRecuento == Ganador.first && iConcursantes > 1 ) {
            Ganador.second = -1;
        }
    }
    cout << Ganador.first << " " << Ganador.second << endl;

    return 0;
}
