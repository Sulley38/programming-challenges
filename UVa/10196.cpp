#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Game = 1;
    bool Terminar = false;
    while( !Terminar ) {
        vector< vector<char> > Tablero( 8, vector<char>(8) );
        int ReyNX = -1, ReyNY = 0, ReyBX = 0, ReyBY = 0;
        // Leer la entrada
        for( int i = 0; i < 8; ++i ) {
            for( int j = 0; j < 8; ++j ) {
                cin >> Tablero[i][j];
                if( Tablero[i][j] == 'K' ) {
                    ReyBX = j;
                    ReyBY = i;
                } else if( Tablero[i][j] == 'k' ) {
                    ReyNX = j;
                    ReyNY = i;
                }
            }
        }
        // Procesa el tablero
        if( ReyNX != -1 ) {
            int i = 0, j = 0;
            bool NAmenazado = false, BAmenazado = false;
            // COMPROBAR REY NEGRO
            i = ReyNY-1;
            j = ReyNX;
            while( !NAmenazado && i >= 0 && Tablero[i][j] == '.' ) i--; // Busca hacia arriba
            if( i >= 0 && (Tablero[i][j] == 'R' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && i == ReyNY-1 ) ) ) NAmenazado = true;
            i = ReyNY+1;
            j = ReyNX;
            while( !NAmenazado && i < 8 && Tablero[i][j] == '.' ) i++; // Busca hacia abajo
            if( i < 8 && (Tablero[i][j] == 'R' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && i == ReyNY+1 ) ) ) NAmenazado = true;
            i = ReyNY;
            j = ReyNX-1;
            while( !NAmenazado && j >= 0 && Tablero[i][j] == '.' ) j--; // Busca hacia la izquierda
            if( j >= 0 && (Tablero[i][j] == 'R' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && j == ReyNX-1 ) ) ) NAmenazado = true;
            i = ReyNY;
            j = ReyNX+1;
            while( !NAmenazado && j < 8 && Tablero[i][j] == '.' ) j++; // Busca hacia la derecha
            if( j < 8 && (Tablero[i][j] == 'R' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && j == ReyNX+1 ) ) ) NAmenazado = true;
            i = ReyNY-1;
            j = ReyNX-1;
            while( !NAmenazado && i >= 0 && j >= 0 && Tablero[i][j] == '.' ) { i--; j--; }// Busca diagonal arriba-izquierda
            if( i >= 0 && j >= 0 && (Tablero[i][j] == 'B' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && i == ReyNY-1 && j == ReyNX-1 ) ) ) NAmenazado = true;
            i = ReyNY-1;
            j = ReyNX+1;
            while( !NAmenazado && i >= 0 && j < 8 && Tablero[i][j] == '.' ) { i--; j++; }// Busca diagonal arriba-derecha
            if( i >= 0 && j < 8 && (Tablero[i][j] == 'B' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && i == ReyNY-1 && j == ReyNX+1 ) ) ) NAmenazado = true;
            i = ReyNY+1;
            j = ReyNX-1;
            while( !NAmenazado && i < 8 && j >= 0 && Tablero[i][j] == '.' ) { i++; j--; }// Busca diagonal abajo-izquierda
            if( i < 8 && j >= 0 && (Tablero[i][j] == 'B' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && i == ReyNY+1 && j == ReyNX-1 ) ) ) NAmenazado = true;
            i = ReyNY+1;
            j = ReyNX+1;
            while( !NAmenazado && i < 8 && j < 8 && Tablero[i][j] == '.' ) { i++; j++; }// Busca diagonal abajo-derecha
            if( i < 8 && j < 8 && (Tablero[i][j] == 'B' || Tablero[i][j] == 'Q' || (Tablero[i][j] == 'K' && i == ReyNY+1 && j == ReyNX+1 ) ) ) NAmenazado = true;
            i = ReyNY;
            j = ReyNX;
            // Peones debajo
            if( !NAmenazado && i+1 < 8 && j-1 >= 0 && Tablero[i+1][j-1] == 'P' ) NAmenazado = true;
            if( !NAmenazado && i+1 < 8 && j+1 < 8 && Tablero[i+1][j+1] == 'P' ) NAmenazado = true;
            // Caballos
            if( !NAmenazado && i-2 >= 0 && j-1 >= 0 && Tablero[i-2][j-1] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i-1 >= 0 && j-2 >= 0 && Tablero[i-1][j-2] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i-2 >= 0 && j+1 < 8 && Tablero[i-2][j+1] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i-1 >= 0 && j+2 < 8 && Tablero[i-1][j+2] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i+2 < 8 && j-1 >= 0 && Tablero[i+2][j-1] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i+1 < 8 && j-2 >= 0 && Tablero[i+1][j-2] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i+2 < 8 && j+1 < 8 && Tablero[i+2][j+1] == 'N' ) NAmenazado = true;
            if( !NAmenazado && i+1 < 8 && j+2 < 8 && Tablero[i+1][j+2] == 'N' ) NAmenazado = true;
            // COMPROBAR REY BLANCO
            if( !NAmenazado ) {
                i = ReyBY-1;
                j = ReyBX;
                while( !BAmenazado && i >= 0 && Tablero[i][j] == '.' ) i--; // Busca hacia arriba
                if( i >= 0 && (Tablero[i][j] == 'r' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && i == ReyBY-1 ) ) ) BAmenazado = true;
                i = ReyBY+1;
                j = ReyBX;
                while( !BAmenazado && i < 8 && Tablero[i][j] == '.' ) i++; // Busca hacia abajo
                if( i < 8 && (Tablero[i][j] == 'r' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && i == ReyBY+1 ) ) ) BAmenazado = true;
                i = ReyBY;
                j = ReyBX-1;
                while( !BAmenazado && j >= 0 && Tablero[i][j] == '.' ) j--; // Busca hacia la izquierda
                if( j >= 0 && (Tablero[i][j] == 'r' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && j == ReyBX-1 ) ) ) BAmenazado = true;
                i = ReyBY;
                j = ReyBX+1;
                while( !BAmenazado && j < 8 && Tablero[i][j] == '.' ) j++; // Busca hacia la derecha
                if( j < 8 && (Tablero[i][j] == 'r' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && j == ReyBX+1 ) ) ) BAmenazado = true;
                i = ReyBY-1;
                j = ReyBX-1;
                while( !BAmenazado && i >= 0 && j >= 0 && Tablero[i][j] == '.' ) { i--; j--; }// Busca diagonal arriba-izquierda
                if( i >= 0 && j >= 0 && (Tablero[i][j] == 'b' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && i == ReyBY-1 && j == ReyBX-1 ) ) ) BAmenazado = true;
                i = ReyBY-1;
                j = ReyBX+1;
                while( !BAmenazado && i >= 0 && j < 8 && Tablero[i][j] == '.' ) { i--; j++; }// Busca diagonal arriba-derecha
                if( i >= 0 && j < 8 && (Tablero[i][j] == 'b' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && i == ReyBY-1 && j == ReyBX+1 ) ) ) BAmenazado = true;
                i = ReyBY+1;
                j = ReyBX-1;
                while( !BAmenazado && i < 8 && j >= 0 && Tablero[i][j] == '.' ) { i++; j--; }// Busca diagonal abajo-izquierda
                if( i < 8 && j >= 0 && (Tablero[i][j] == 'b' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && i == ReyBY+1 && j == ReyBX-1 ) ) ) BAmenazado = true;
                i = ReyBY+1;
                j = ReyBX+1;
                while( !BAmenazado && i < 8 && j < 8 && Tablero[i][j] == '.' ) { i++; j++; }// Busca diagonal abajo-derecha
                if( i < 8 && j < 8 && (Tablero[i][j] == 'b' || Tablero[i][j] == 'q' || (Tablero[i][j] == 'k' && i == ReyBY+1 && j == ReyBX+1 ) ) ) BAmenazado = true;
                i = ReyBY;
                j = ReyBX;
                // Peones encima
                if( !BAmenazado && i-1 >= 0 && j-1 >= 0 && Tablero[i-1][j-1] == 'p' ) BAmenazado = true;
                if( !BAmenazado && i-1 >= 0 && j+1 < 8 && Tablero[i-1][j+1] == 'p' ) BAmenazado = true;
                // Caballos
                if( !BAmenazado && i-2 >= 0 && j-1 >= 0 && Tablero[i-2][j-1] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i-1 >= 0 && j-2 >= 0 && Tablero[i-1][j-2] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i-2 >= 0 && j+1 < 8 && Tablero[i-2][j+1] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i-1 >= 0 && j+2 < 8 && Tablero[i-1][j+2] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i+2 < 8 && j-1 >= 0 && Tablero[i+2][j-1] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i+1 < 8 && j-2 >= 0 && Tablero[i+1][j-2] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i+2 < 8 && j+1 < 8 && Tablero[i+2][j+1] == 'n' ) BAmenazado = true;
                if( !BAmenazado && i+1 < 8 && j+2 < 8 && Tablero[i+1][j+2] == 'n' ) BAmenazado = true;
            }

            if( NAmenazado )
                cout << "Game #" << Game << ": black king is in check." << endl;
            else if( BAmenazado )
                cout << "Game #" << Game << ": white king is in check." << endl;
            else
                cout << "Game #" << Game << ": no king is in check." << endl;
            Game++;
        } else {
            Terminar = true;
        }
    }

    return 0;
}
