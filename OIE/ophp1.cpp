#include <iostream>

using namespace std;

int main()
{
    string s;
    while( getline( cin, s ) ) {
        int i = 0;
        while( s[i] == ' ' && i < int(s.size()) ) i++;
        if( s[i] != '#' ) cout << s << endl;
    }

    return 0;
}

