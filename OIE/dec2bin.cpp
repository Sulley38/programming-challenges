#include <iostream>

using namespace std;

string Dividir( const string& N )
{
    string Res;
    int T = N.size(), Llevada = 0;
    for( int i = 0; i < T; ++i ) {
        Res.push_back( ( Llevada*10 + N[i]-'0')/2 + '0' );
        Llevada = (Llevada*10 + N[i]-'0') % 2;
    }
    while( Res.size() > 1 && Res[0] == '0' ) Res.erase(0,1);
    return Res;
}

int main()
{
    string e;
    while( cin >> e ) {
        string s;
        if( e == "0" ) s = e;
        int Tam = e.size();
        while( e != "0" ) {
            if( e[Tam-1] == '0' || e[Tam-1] == '2' || e[Tam-1] == '4' || e[Tam-1] == '6' || e[Tam-1] == '8' ) {
                s.insert( 0, "0" );
            } else {
                s.insert( 0, "1" );
                e[Tam-1] = e[Tam-1]-1;
            }
            e = Dividir(e);
            Tam = e.size();
        }
        cout << s << endl;
    }
    return 0;
}
