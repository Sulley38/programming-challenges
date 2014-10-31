#include <iostream>
#include <vector>

using namespace std;
vector<int> Combinaciones( 13 );

int Suma( const int& Inicio, const int& Fin ) {
    int Index = Inicio, Res = 0;
    while( Index > 1 && Index < 13 ) {
        Res += Combinaciones[Index];
        if( Inicio > Fin ) Index--;
        else Index++;
    }
    return Res;
}

int Probabilidad( const int& Dados, const int& Puntuacion, const string& Operacion )
{
    if( Dados == 1 ) {
        if( Operacion == "=" && Puntuacion >= 1 && Puntuacion <= 6 ) return 6;
        else if( Operacion == "<=" && Puntuacion >= 1 )
            if( Puntuacion > 6 ) return 36; else return Puntuacion*6;
        else if( Operacion == ">=" && Puntuacion <= 6 )
            if( Puntuacion < 1 ) return 36; else return (7-Puntuacion)*6;
        else if( Operacion == "<" && Puntuacion > 1 )
            if( Puntuacion > 6 ) return 36; else return (Puntuacion-1)*6;
        else if( Operacion == ">" && Puntuacion < 6 )
            if( Puntuacion < 1 ) return 36; else return (6-Puntuacion)*6;
        else return 0;
    } else {
        if( Operacion == "=" && Puntuacion >= 2 && Puntuacion <= 12 ) return Combinaciones[Puntuacion];
        else if( Operacion == "<=" && Puntuacion >= 2 )
            if( Puntuacion > 12 ) return 36; else return Suma( Puntuacion, 1 );
        else if( Operacion == ">=" && Puntuacion <= 12 )
            if( Puntuacion < 2 ) return 36; else return Suma( Puntuacion, 13 );
        else if( Operacion == "<" && Puntuacion > 2 )
            if( Puntuacion > 12 ) return 36; else return Suma( Puntuacion-1, 1 );
        else if( Operacion == ">" && Puntuacion < 12 )
            if( Puntuacion < 2 ) return 36; else return Suma( Puntuacion+1, 13 );
        else return 0;
    }
}

int main()
{
    Combinaciones[2] = 1; Combinaciones[3] = 2; Combinaciones[4] = 3; Combinaciones[5] = 4; Combinaciones[6] = 5;
    Combinaciones[7] = 6; Combinaciones[8] = 5; Combinaciones[9] = 4; Combinaciones[10] = 3; Combinaciones[11] = 2; Combinaciones[12] = 1;

    int K1, K2, P1, P2, R1, R2;
    string OP1, OP2;
    while( cin >> K1 >> OP1 >> P1 >> K2 >> OP2 >> P2 ) {
        R1 = Probabilidad( K1, P1, OP1 );
        R2 = Probabilidad( K2, P2, OP2 );
        if( R1 < R2 ) cout << "B" << endl;
        else if( R1 > R2 ) cout << "A" << endl;
        else cout << "=" << endl;

        cin.ignore( 4 );
    }

    return 0;
}
