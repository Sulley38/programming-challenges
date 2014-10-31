#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<char> > Matrix;
typedef vector< vector<string> > Piezas;

// Variables globales
int g_iSemilla, g_iMarcador = 0, g_iNivel = 1, g_iLineas = 0, g_iPieza = 0,
    g_iPX = 0, g_iPY = 0,g_iPWidth = 0, g_iPHeight = 0, g_iAlto, g_iAncho;
Matrix g_Tablero;
Piezas g_Piezas( 7 );

// Procedimientos
int NextPieza() {
    g_iSemilla = ( 13821*g_iSemilla ) % 32768;
    return g_iSemilla % 7;
}

void CrearPiezas()
{
    g_Piezas[0].push_back("#"); g_Piezas[0].push_back("#"); g_Piezas[0].push_back("#"); g_Piezas[0].push_back("#");
    g_Piezas[1].push_back("##"); g_Piezas[1].push_back("##");
    g_Piezas[2].push_back(".#."); g_Piezas[2].push_back("###");
    g_Piezas[3].push_back("#.."); g_Piezas[3].push_back("###");
    g_Piezas[4].push_back("..#"); g_Piezas[4].push_back("###");
    g_Piezas[5].push_back("#."); g_Piezas[5].push_back("##"); g_Piezas[5].push_back(".#");
    g_Piezas[6].push_back(".#"); g_Piezas[6].push_back("##"); g_Piezas[6].push_back("#.");
}

void SubirPuntuacion( const int& Lineas )
{
    int Puntuaciones[5] = { 0, 1, 3, 6, 10 };
    g_iMarcador += g_iNivel*Puntuaciones[Lineas];
    // Subir nivel si corresponde
    g_iLineas += Lineas;
    if( g_iLineas > 10 ) {
        g_iNivel++;
        g_iLineas -= 10;
    }
}

void Movimiento( const int& X, const int& Y )
{
    Matrix Tablero = g_Tablero;
    for( int i = 0; i < g_iPHeight; i++ )
        for( int j = 0; j < g_iPWidth; j++ )
            if( g_Tablero[g_iPY+i][g_iPX+j] == '#' ) g_Tablero[g_iPY+i][g_iPX+j] = '.';
    for( int i = 0; i < g_iPHeight; i++ )
        for( int j = 0; j < g_iPWidth; j++ )
            if( Tablero[g_iPY+i][g_iPX+j] == '#' ) g_Tablero[g_iPY+i+Y][g_iPX+j+X] = '#';
}

bool Insertar()
{
    // Devuelve false si correcto, true si choca
    g_iPieza = NextPieza(); // Obtiene una nueva pieza
    g_iPHeight = g_Piezas[g_iPieza].size();
    g_iPWidth = g_Piezas[g_iPieza][0].size();
    g_iPX = (g_iAncho/2)-1;
    g_iPY = 0;

    bool Res = false;
    for( int i = 0; i < g_iPHeight; i++ ) {
        for( int j = 0; j < g_iPWidth; j++ ) {
            if( g_Tablero[i][(g_iAncho/2)-1+j] != '.' && g_Piezas[g_iPieza][i][j] == '#' ) {
                g_Tablero[i][(g_iAncho/2)-1+j] = '!';
                Res = true;
            } else {
                g_Tablero[i][(g_iAncho/2)-1+j] = g_Piezas[g_iPieza][i][j];
            }
        }
    }
    return Res;
}

bool MovAbajo()
{
    // Comprobar si es posible
    bool Valido = true;
    for( int i = 0; i < g_iPHeight; i++ )
        for( int j = 0; j < g_iPWidth; j++ )
            if( g_Tablero[g_iPY+i][g_iPX+j] == '#' && ( g_iPY+i+1 < 0 || g_iPY+i+1 >= g_iAlto || g_Tablero[g_iPY+i+1][g_iPX+j] == 'X' ) ) {
                Valido = false; i = g_iPHeight; j = g_iPWidth; }

    if( Valido ) { // Realizar el movimiento
        Movimiento( 0, 1 );
        g_iPY++;
        return false;
    } else { // Asegurar pieza
        for( int i = 0; i < g_iPHeight; i++ )
            for( int j = 0; j < g_iPWidth; j++ )
                if( g_Tablero[g_iPY+i][g_iPX+j] == '#' ) g_Tablero[g_iPY+i][g_iPX+j] = 'X';
        // Eliminar filas y subir marcador
        int iLineas = 0;
        for( int i = 0; i < g_iAlto; i++ ) {
            int Cuenta = 0;
            for( int j = 0; j < g_iAncho; j++ ) if( g_Tablero[i][j] == 'X' ) Cuenta++;
            if( Cuenta == g_iAncho ) {
                for( int k = i; k > 0; k-- )
                    for( int j = 0; j < g_iAncho; j++ ) g_Tablero[k][j] = g_Tablero[k-1][j];
                for( int j = 0; j < g_iAncho; j++ ) g_Tablero[0][j] = '.';
                iLineas++;
                i = -1;
            }
        }
        SubirPuntuacion( iLineas );
        return Insertar();
    }
}

void MovLateral( const int& Dir )
{
    // Comprobar si es posible
    bool Valido = true;
    for( int i = 0; i < g_iPHeight; i++ )
        for( int j = 0; j < g_iPWidth; j++ )
            if( g_Tablero[g_iPY+i][g_iPX+j] == '#' && ( g_iPX+j+Dir < 0 || g_iPX+j+Dir >= g_iAncho || g_Tablero[g_iPY+i][g_iPX+j+Dir] == 'X' ) ) {
                Valido = false; i = g_iPHeight; j = g_iPWidth; }

    // Realizar el movimiento
    if( Valido ){
        Movimiento( Dir, 0 );
        g_iPX += Dir;
    }
}

void Rotar()
{
    // Comprobar si es posible
    int Desfase = 0;
    bool Valido = true;
    for( int i = 0; i < g_iPWidth; i++ ) {
        for( int j = 0; j < g_iPHeight; j++ ) {
            // Se necesita desplazar?
            if( g_Tablero[g_iPY+j][g_iPX+g_iPWidth-1-i] == '#' && g_iPX+j+Desfase < 0 ) {
                Desfase++; // Desplazar uno a la derecha y volver a comprobar
                i = 0; j = -1; Valido = true;
            } else if( g_Tablero[g_iPY+j][g_iPX+g_iPWidth-1-i] == '#' && g_iPX+j+Desfase >= g_iAncho ) {
                Desfase--; // Desplazar uno a la izquierda y volver a comprobar
                i = 0; j = -1; Valido = true;
            } else if( g_Tablero[g_iPY+j][g_iPX+g_iPWidth-1-i] == '#' && ( g_iPY+i < 0 || g_iPY+i >= g_iAlto || g_Tablero[g_iPY+i][g_iPX+j+Desfase] == 'X' ) ) {
                Valido = false;
            }
        }
    }

    if( Valido ) { // Realizar el movimiento de rotacion
        Matrix Tablero = g_Tablero;
        for( int i = 0; i < g_iPHeight; i++ )
            for( int j = 0; j < g_iPWidth; j++ )
                if( g_Tablero[g_iPY+i][g_iPX+j] == '#' ) g_Tablero[g_iPY+i][g_iPX+j] = '.';
        for( int i = 0; i < g_iPWidth; i++ )
            for( int j = 0; j < g_iPHeight; j++ )
                if( Tablero[g_iPY+j][g_iPX+g_iPWidth-1-i] == '#' ) g_Tablero[g_iPY+i][g_iPX+j+Desfase] = '#';
        swap( g_iPHeight, g_iPWidth );
        g_iPX += Desfase;
    }
}

void Print()
{
    cout << "Score: " << g_iMarcador << endl;
    for( int i = 0; i < g_iAlto; i++ ) {
        for( int j = 0; j < g_iAncho; j++ ) cout << g_Tablero[i][j];
        cout << endl;
    }
    for( int i = 0; i < g_iAncho; i++ ) cout << "-";
    cout << endl;
}

int main()
{
    cin >> g_iSemilla >> g_iAlto >> g_iAncho;
    cin.ignore(1,'\n');
    g_Tablero.resize( g_iAlto );
    for( int i = 0; i < g_iAlto; i++ ) g_Tablero[i].resize( g_iAncho, '.' );
    CrearPiezas(); // Dibujar las piezas en el contenedor
    Insertar(); // Introducir la primera pieza

    string s;
    bool Seguir = true;
    while( getline( cin, s ) && Seguir ) {
        for( int i = 0; i < int(s.size()); i++ ) {
            // Realizar movimiento
            if( s[i] == '2' ) {
                if( MovAbajo() ) {
                    i = s.size();
                    Seguir = false;
                }
            } else if( s[i] == '4' ) {
                MovLateral( -1 );
            } else if( s[i] == '5' ) {
                Rotar();
            } else if( s[i] == '6' ) {
                MovLateral( 1 );
            }
        }

        Print(); // Escribir en pantalla
    }

    return 0;
}
