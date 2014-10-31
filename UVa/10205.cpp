#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int Casos;
    cin >> Casos;
    while( Casos-- ) {
        int N;
        cin >> N;
        // Leer las mezclas
        vector< vector<int> > Mezcla(N,vector<int>(52));
        for( int i = 0; i < N; ++i )
            for( int j = 0; j < 52; ++j )
                cin >> Mezcla[i][j];
        cin.ignore(1);
        vector<int> Mazo(52), MazoMezclado(52); // Mazo inicial
        for( int i = 0; i < 52; ++i )
            Mazo[i] = i+1;
        // Aplicar las mezclas
        int K;
        string s;
        while( getline(cin,s) && s != "" ) {
            istringstream ss(s);
            ss >> K;
            for( int j = 0; j < 52; ++j )
                MazoMezclado[j] = Mazo[Mezcla[K-1][j]-1];
            Mazo = MazoMezclado;
        }
        // Mostrar el resultado
        int Valor, Palo;
        for( int i = 0; i < 52; ++i ) {
            Valor = (Mazo[i]%13)+1;
            Palo = (Mazo[i]-1)/13;
            if( Valor >= 2 && Valor <= 10 )
                cout << Valor << " of ";
            else if( Valor == 11 )
                cout << "Jack of ";
            else if( Valor == 12 )
                cout << "Queen of ";
            else if( Valor == 13 )
                cout << "King of ";
            else if( Valor == 1 )
                cout << "Ace of ";
            if( Palo == 0 )
                cout << "Clubs" << endl;
            else if( Palo == 1 )
                cout << "Diamonds" << endl;
            else if( Palo == 2 )
                cout << "Hearts" << endl;
            else if( Palo == 3 )
                cout << "Spades" << endl;
        }
        if( Casos > 0 ) cout << endl;
    }
    return 0;
}
