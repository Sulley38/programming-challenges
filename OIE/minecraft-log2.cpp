#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string X, Y;
    set<string> Jugadores;
    while(N--) {
        cin >> X >> Y;
        if( X == "entra" ) {
            if( Jugadores.count(Y) == 0 ) {
                Jugadores.insert(Y);
                cout << Y << " logged in to the server." << endl;
            }
        } else {
            if( Jugadores.count(Y) > 0 ) {
                Jugadores.erase(Y);
                cout << Y << " logged out of the server." << endl;
            }
        }
    }
    cout << "Connected players: " << Jugadores.size() << endl;
    return 0;
}
