#include <iostream>
#include <vector>

using namespace std;

bool Match( int X, int Y, const string& Palabra, const vector< vector<char> >& T, const int& Alto, const int& Ancho )
{
    int Tam = Palabra.size();
    // Arriba
    if( Y-Tam+1 >= 0 ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y-i][X] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y-i][X] ) return true;
        }
    }
    // Abajo
    if( Y+Tam <= Alto ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y+i][X] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y+i][X] ) return true;
        }
    }
    // Izquierda
    if( X-Tam+1 >= 0 ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y][X-i] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y][X-i] ) return true;
        }
    }
    // Derecha
    if( X+Tam <= Ancho ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y][X+i] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y][X+i] ) return true;
        }
    }
    // Arriba-izquierda
    if( Y-Tam+1 >= 0 && X-Tam+1 >= 0 ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y-i][X-i] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y-i][X-i] ) return true;
        }
    }
    // Arriba-derecha
    if( Y-Tam+1 >= 0 && X+Tam <= Ancho ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y-i][X+i] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y-i][X+i] ) return true;
        }
    }
    // Abajo-izquierda
    if( Y+Tam <= Alto && X-Tam+1 >= 0 ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y+i][X-i] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y+i][X-i] ) return true;
        }
    }
    // Abajo-derecha
    if( Y+Tam <= Alto && X+Tam <= Ancho ) {
        for( int i = 0; i < Tam; ++i ) {
            if( Palabra[i] != T[Y+i][X+i] ) i = Tam;
            else if( i == Tam-1 && Palabra[i] == T[Y+i][X+i] ) return true;
        }
    }
    return false;
}

int main()
{
    int Casos;
    cin >> Casos;
    while( Casos-- ) {
        // Leer la tabla
        int M, N;
        cin >> M >> N;
        vector< vector<char> > Tabla( M, vector<char>(N) );
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                cin >> Tabla[i][j];
                if( Tabla[i][j] >= 'a' ) // Mayusculizar
                    Tabla[i][j] -= 32;
            }
        }
        // Buscar las palabras
        int Palabras, Size;
        string Obj;
        cin >> Palabras;
        while( Palabras-- ) {
            cin >> Obj;
            Size = Obj.size();
            for( int i = 0; i < Size; ++i ) // Mayusculizar
                if( Obj[i] >= 'a' ) Obj[i] -= 32;
            // Buscar la palabra
            int X, Y;
            for( int i = 0; i < M; ++i )
                for( int j = 0; j < N; ++j )
                    if( Match(j,i,Obj,Tabla,M,N) )
                        { X = j; Y = i; i = M; j = N; }

            cout << Y+1 << " " << X+1 << endl;
        }
        if( Casos > 0 )
            cout << endl;
    }

    return 0;
}
