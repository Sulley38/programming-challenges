#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int GetPosicion( const vector<int>& Posiciones, const int& Bola, const int& Longitud, const int& Segundos )
{
    int Pos = 0, NumBolas = int(Posiciones.size())-2;
    int PrimerMov = Posiciones[Bola] - ( Bola-1 );
    int SegundoMov = Longitud - NumBolas + ( Longitud - Posiciones[Bola+1]+1 - ( NumBolas - Bola - 1 ) );

    if( Segundos < PrimerMov ) { // No se mueve
        Pos = Posiciones[Bola];
    } else if( Segundos < SegundoMov ) { // Se mueve en la ida
        if( Segundos - PrimerMov < Posiciones[Bola+1] - 1 - Posiciones[Bola] )
            Pos = Posiciones[Bola]+1 + ( Segundos - PrimerMov );
        else
            Pos = Posiciones[Bola+1]-1;
    } else { // Se mueve en la vuelta
        if( Segundos - SegundoMov < Posiciones[Bola+1] - 1 - Posiciones[Bola] )
            Pos = Posiciones[Bola+1]-2 - ( Segundos - SegundoMov );
        else
            Pos = Posiciones[Bola];
    }

    return Pos;
}

int main()
{
    int iLongitud, iBolas, iPreguntas;
    while( cin >> iLongitud >> iBolas ) {

        vector<int> Posiciones( iBolas+2 );
        for( int i = 1; i < iBolas+1; i++ )
            cin >> Posiciones[i];
        Posiciones[iBolas+1] = iLongitud+1;
        sort( Posiciones.begin(), Posiciones.end() );

        cin >> iPreguntas;
        while( iPreguntas-- ) {
            int Bola, Tiempo;
            cin >> Bola >> Tiempo;
            int Res = GetPosicion( Posiciones, Bola, iLongitud, Tiempo % ( 2*iLongitud - 2*iBolas ) );
            cout << "Ball " << Bola << ", time " << Tiempo << ": " << Res << endl;
        }

        cout << endl;
    }

    return 0;
}
