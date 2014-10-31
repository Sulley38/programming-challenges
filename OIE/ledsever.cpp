#include <iostream>

using namespace std;

int main()
{
    string s1;
    while( cin >> s1 ) {
        string s2;
        for( string::iterator it = s1.end()-1; it != s1.begin()-1; it-- )
            s2.push_back( *it );
        cout << s2 << endl;
    }

    return 0;
}
