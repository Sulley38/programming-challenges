#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define GRAVEDAD 9.81

using namespace std;

pair<float,float> MaximoMinimo( const vector<float>& Coeficientes )
{
    vector<float> Derivado( 3 ), Derivado2( 2 );
    float Res1, Res2;

    Derivado[0] = 3*Coeficientes[0];
    Derivado[1] = 2*Coeficientes[1];
    Derivado[2] = Coeficientes[2];

    Res1 = ( -Derivado[1] + sqrt( Derivado[1]*Derivado[1] - 4*Derivado[0]*Derivado[2] ) ) / ( 2*Derivado[0] );
    Res2 = ( -Derivado[1] - sqrt( Derivado[1]*Derivado[1] - 4*Derivado[0]*Derivado[2] ) ) / ( 2*Derivado[0] );

    Derivado2[0] = 2*Derivado[0];
    Derivado2[1] = Derivado[1];

    if( Derivado2[0]*Res1 + Derivado2[1] < 0 )
        return pair<float,float>( Res1, Res2 );
    else
        return pair<float,float>( Res2, Res1 );
}

float GetEnergiaPotencial( const float& Masa, const float& Altura )
{
    return Masa*GRAVEDAD*Altura;
}

float GetAltura( const vector<float>& Coef, const float& Valor )
{
    return Coef[0]*Valor*Valor*Valor + Coef[1]*Valor*Valor + Coef[2]*Valor + Coef[3];
}

float GetVelocidad( const float& Energia, const float& Masa )
{
    return sqrt( ( 2*Energia ) / Masa );
}

int main()
{
    int Casos = 0;
    cin >> Casos;
    while( Casos-- ) {
        vector<float> Coeficientes( 4 );
        float fMasa, fA, fB, Velocidad;
        cin >> Coeficientes[0] >> Coeficientes[1] >> Coeficientes[2] >> Coeficientes[3] >> fMasa >> fA >> fB;

        pair<float,float> Puntos = MaximoMinimo( Coeficientes );
        vector<float> Energias( 0 );
        Energias.push_back( GetEnergiaPotencial( fMasa, GetAltura( Coeficientes, fA ) ) );
        Energias.push_back( GetEnergiaPotencial( fMasa, GetAltura( Coeficientes, fB ) ) );
        if( Puntos.first > fA && Puntos.first < fB ) {
            Energias.push_back( GetEnergiaPotencial( fMasa, GetAltura( Coeficientes, Puntos.first ) ) );
        }
        if( Puntos.second > fA && Puntos.second < fB ) {
            Energias.push_back( GetEnergiaPotencial( fMasa, GetAltura( Coeficientes, Puntos.second ) ) );
        }

        float EnergiaPI = *max_element( Energias.begin(), Energias.end() );
        float EnergiaPF = *min_element( Energias.begin(), Energias.end() );
        Velocidad = GetVelocidad( EnergiaPI - EnergiaPF, fMasa );

        if( Velocidad*3.6 > 120 ) cout << "Crash!" << endl;
        else cout << "No problem" << endl;
    }

    return 0;
}
