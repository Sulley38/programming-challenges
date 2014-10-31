#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Players = 0;
    cin >> N;
    string X, Y;
    while(N--) {
        cin >> X >> Y;
        if( X == "entra" ) {
            cout << Y << " logged in to the server." << endl;
            Players++;
        } else {
            cout << Y << " logged out of the server." << endl;
            Players--;
        }
    }
    cout << "Connected players: " << Players << endl;
    return 0;
}
