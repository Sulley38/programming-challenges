#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
void TratarFlorBuena( const vector< vector<char> >& Jardin, const int iFila );
void EliminarIncortables( vector< vector<char> >& Jardin );
pair<int,int> EstudiarRentabilidad( const int& iCosteCorte, const int& iBeneficioCorte );
vector<int> vHojas;

void TratarFlorBuena( const vector< vector<char> >& Jardin, const int iFila )
{
    int iHojas = 0;

    for( int b = 1; b < int(Jardin[iFila].size())-1; b++ ) {
        if( Jardin[iFila-1][b] == 'b' )
            iHojas++;
    } for( int b = 1; b < int(Jardin[iFila].size())-1; b++ ) {
        if( Jardin[iFila+1][b] == 'P' )
            iHojas++;
    }

    vHojas.push_back( iHojas );
}

void EliminarIncortables( vector< vector<char> >& Jardin )
{
    for( int a = 1; a < int(Jardin.size())-1; a++ ) {
        if( Jardin[a][1] == '-' ) {
            bool bFlor = false;
            for( int b = 1; b < int(Jardin[a].size())-1; b++ ) {
                if( Jardin[a][b] == 'x' )
                    if( Jardin[a-1][b] == 'x' )
                        if( Jardin[a+1][b] == 'x' )
                            if( Jardin[a][b+1] == 'x' )
                                if( Jardin[a-1][b+1] == 'x' )
                                    if( Jardin[a+1][b+1] == 'x' )
                                        if( Jardin[a][b+2] == 'x' )
                                            if( Jardin[a-1][b+2] == 'x' )
                                                if( Jardin[a+1][b+2] == 'x' )
                                                    bFlor = true;
            }
            if( bFlor == true ) {
                TratarFlorBuena( Jardin, a );
            } else {
                for( int b = 1; b < int(Jardin[a].size())-1; b++ ) {
                    if( Jardin[a][b] == '-' )
                        Jardin[a][b] = ' ';
                }
            }
        }
    }
}

pair<int,int> EstudiarRentabilidad( const int& iCosteCorte, const int& iBeneficioCorte )
{
    int iCortesTotal = 0, iBeneficioMax = 0, iBeneficioLast = -1;
    priority_queue<int> pqCortes;
    for( int i = 0; i < int(vHojas.size()); i++ ) {
        pqCortes.push( vHojas[i] );
    }

    while( iBeneficioMax > iBeneficioLast && !pqCortes.empty() ) {
        iBeneficioLast = iBeneficioMax;
        iBeneficioMax += pqCortes.top() * iBeneficioCorte;
        iBeneficioMax -= iCosteCorte;
        pqCortes.pop();
        iCortesTotal++;
    }
    if( iBeneficioMax > iBeneficioLast && pqCortes.empty() ) {
        iBeneficioLast = iBeneficioMax;
        iCortesTotal++;
    }

    pair<int,int> Resultado( iBeneficioLast, iCortesTotal-1 );
    return Resultado;
}

int main()
{
    int iCoste = 0, iBeneficio = 0, iLongitud = 0;
    string Entrada;
    cin >> iCoste >> iBeneficio >> iLongitud;
    cin.ignore();

    vector< vector<char> > vJardin;
    vector<char> vFila;

    vFila.resize( 80, '0' );
    vJardin.push_back( vFila );
    vFila.clear();
    while( iLongitud-- ) {
        getline( cin, Entrada );
        unsigned int i = 0;
        vFila.push_back( '0' );
        while( i < Entrada.size() ) {
            vFila.push_back( Entrada[i] );
            i++;
        }
        vFila.push_back( '0' );
        vJardin.push_back( vFila );
        vFila.clear();
    }
    vFila.resize( 80, '0' );
    vJardin.push_back( vFila );

    EliminarIncortables( vJardin );

    pair<int,int> Datos;
    Datos = EstudiarRentabilidad( iCoste, iBeneficio );
    cout << Datos.first << endl;
    cout << Datos.second << endl;

    return 0;
}
