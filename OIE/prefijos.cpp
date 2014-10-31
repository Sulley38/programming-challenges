#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<string,string> PSS; // Primero prefijo, segundo palabra

void RellenarPrefijos( vector<PSS>& Cont, const int& Palabras );

bool OrdenA ( const PSS& a, const PSS& b ) { return a.second < b.second; }
bool OrdenB ( const PSS& a, const PSS& b ) {
    if( a.first.size() != b.first.size() ) return a.first.size() < b.first.size();
    else return a.first < b.first;
}

void RellenarPrefijos( vector<PSS>& Cont, const int& Palabras ) {
    int Pos1 = 0, Pos2 = 0, n = 0;
    // Primera palabra
    while( Cont[n].second[Pos1] == Cont[n+1].second[Pos1] ) Pos1++;
    Cont[n].first = Cont[n].second.substr( 0, Pos1+1 );
    // Palabras centrales
    for( n++; n < Palabras-1; n++ ) {
        Pos1 = 0;
        Pos2 = 0;
        while( Cont[n].second[Pos1] == Cont[n+1].second[Pos1] ) Pos1++;
        while( Cont[n].second[Pos2] == Cont[n-1].second[Pos2] ) Pos2++;
        Cont[n].first = Cont[n].second.substr( 0, max( Pos1, Pos2 )+1 );
    }
    // Ultima palabra
    Pos1 = 0;
    while( Cont[n].second[Pos1] == Cont[n-1].second[Pos1] ) Pos1++;
    Cont[n].first = Cont[n].second.substr( 0, Pos1+1 );
}

int main()
{
    int Palabras;
    cin >> Palabras;

    while( Palabras != 0 ) {
        vector<PSS> Words( Palabras );
        for( int i = 0; i < Palabras; i++ )
            cin >> Words[i].second;

        stable_sort( Words.begin(), Words.end(), OrdenA );
        RellenarPrefijos( Words, Palabras );
        stable_sort( Words.begin(), Words.end(), OrdenB );

        for( int i = 0; i < Palabras; i++ )
            cout << Words[i].first << " " << Words[i].second << endl;

        if( cin >> Palabras )
            cout << "----------" << endl;
        else
            Palabras = 0;
    }

    return 0;
}
