#include <iostream>
#include <sstream>
#include <map>

using namespace std;
int leer_programa( map<int,string>& instrucciones );

int leer_programa( map<int,string>& instrucciones )
{
    int iCurrent;
    string Entrada;

    while( getline( cin, Entrada) ) {
        istringstream iss( Entrada );
        iss >> iCurrent;
        instrucciones[iCurrent].assign( Entrada, 4, 16 );
    }

    return iCurrent+1;
}

int main()
{
    map<int,int> mVariable;
    map<int,string> mInstruccion;
    int iCurrent = 0, iFinal = 0;

    for( int i = 0; i < 100; i++ ) {
        mVariable[i] = 1;
    }
    iFinal = leer_programa( mInstruccion );

    while( mInstruccion[iCurrent] != "" ){

        string Command;
        istringstream iss( mInstruccion[iCurrent] );
        iss >> Command;

        if( Command == "stop" ) {
            iCurrent = iFinal;
        } else if( Command == "endl" ) {
            cout << endl;
            iCurrent++;
        } else if( Command == "prin" ) {
            int iVariable;
            iss >> iVariable;
            cout << " " << mVariable[iVariable];
            iCurrent++;
        } else if( Command == "stor" ) {
            int iVariable, iValor;
            iss >> iVariable >> iValor;
            mVariable[iVariable] = iValor;
            iCurrent++;
        } else if( Command == "copy" ) {
            int iVariable1, iVariable2;
            iss >> iVariable1 >> iVariable2;
            mVariable[iVariable1] = mVariable[iVariable2];
            iCurrent++;
        } else if( Command == "acum" ) {
            int iVariable1, iVariable2;
            iss >> iVariable1 >> iVariable2;
            mVariable[iVariable1] += mVariable[iVariable2];
            iCurrent++;
        } else if( Command == "subs" ) {
            int iVariable1, iVariable2;
            iss >> iVariable1 >> iVariable2;
            mVariable[iVariable1] -= mVariable[iVariable2];
            iCurrent++;
        } else if( Command == "prod" ) {
            int iVariable1, iVariable2;
            iss >> iVariable1 >> iVariable2;
            mVariable[iVariable1] *= mVariable[iVariable2];
            iCurrent++;
        } else if( Command == "goto" ) {
            int iPosicion;
            iss >> iPosicion;
            iCurrent = iPosicion;
        } else if( Command == "jzer" ) {
            int iVariable, iPosicion;
            iss >> iVariable >> iPosicion;
            if( mVariable[iVariable] == 0 )
                iCurrent = iPosicion;
            else
                iCurrent++;
        } else if( Command == "jneg" ) {
            int iVariable, iPosicion;
            iss >> iVariable >> iPosicion;
            if( mVariable[iVariable] < 0 )
                iCurrent = iPosicion;
            else
                iCurrent++;
        }

    }

    return 0;
}
