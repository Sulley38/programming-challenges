#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    while( cin >> N ) {
        vector<bool> Posibles(12,true);
        vector<string> Res;
        string Nota;
        while(N--) {
            cin >> Nota;
            if( Nota == "C" ) {
                Posibles[2] = false; Posibles[4] = false; Posibles[6] = false; Posibles[9] = false; Posibles[11] = false;
            } else if( Nota == "C#" ) {
                Posibles[0] = false; Posibles[3] = false; Posibles[5] = false; Posibles[7] = false; Posibles[10] = false;
            } else if( Nota == "D" ) {
                Posibles[1] = false; Posibles[4] = false; Posibles[6] = false; Posibles[8] = false; Posibles[11] = false;
            } else if( Nota == "D#" ) {
                Posibles[0] = false; Posibles[2] = false; Posibles[5] = false; Posibles[7] = false; Posibles[9] = false;
            } else if( Nota == "E" ) {
                Posibles[1] = false; Posibles[3] = false; Posibles[6] = false; Posibles[8] = false; Posibles[10] = false;
            } else if( Nota == "F" ) {
                Posibles[2] = false; Posibles[4] = false; Posibles[7] = false; Posibles[9] = false; Posibles[11] = false;
            } else if( Nota == "F#" ) {
                Posibles[0] = false; Posibles[3] = false; Posibles[5] = false; Posibles[8] = false; Posibles[10] = false;
            } else if( Nota == "G" ) {
                Posibles[1] = false; Posibles[4] = false; Posibles[6] = false; Posibles[9] = false; Posibles[11] = false;
            } else if( Nota == "G#" ) {
                Posibles[0] = false; Posibles[2] = false; Posibles[5] = false; Posibles[7] = false; Posibles[10] = false;
            } else if( Nota == "A" ) {
                Posibles[1] = false; Posibles[3] = false; Posibles[6] = false; Posibles[8] = false; Posibles[11] = false;
            } else if( Nota == "A#" ) {
                Posibles[0] = false; Posibles[2] = false; Posibles[4] = false; Posibles[7] = false; Posibles[9] = false;
            } else if( Nota == "B" ) {
                Posibles[1] = false; Posibles[3] = false; Posibles[5] = false; Posibles[8] = false; Posibles[10] = false;
            }
        }

        if( Posibles[9] == true )Res.push_back( "A" );
        if( Posibles[10] == true ) Res.push_back( "A#" );
        if( Posibles[11] == true ) Res.push_back( "B" );
        if( Posibles[0] == true ) Res.push_back( "C" );
        if( Posibles[1] == true ) Res.push_back( "C#" );
        if( Posibles[2] == true ) Res.push_back( "D" );
        if( Posibles[3] == true ) Res.push_back( "D#" );
        if( Posibles[4] == true ) Res.push_back( "E" );
        if( Posibles[5] == true ) Res.push_back( "F" );
        if( Posibles[6] == true ) Res.push_back( "F#" );
        if( Posibles[7] == true ) Res.push_back( "G" );
        if( Posibles[8] == true ) Res.push_back( "G#" );

        if( int(Res.size()) == 0 ) Res.push_back( "None" );

        cout << Res[0];
        for( int i = 1; i < int(Res.size()); ++i )
            cout << " " << Res[i];
        cout << endl;
    }

    return 0;
}
