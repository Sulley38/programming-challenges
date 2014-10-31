#include <iostream>

using namespace std;

int main()
{
    unsigned int iLength;
    string e, s;
    cin >> iLength;
    while( cin >> e ) {
        if( s.size() + e.size() <= iLength ) {
            s += e + " ";
        } else {
            s.erase( s.end()-1 );
            cout << s << endl;
            s = e + " ";
        }
    }
    s.erase( s.end()-1 );
    cout << s << endl;

    return 0;
}
