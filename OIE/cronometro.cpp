#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n, min, seg, mil;
    while( cin >> n && n >= 0 ) {
        min = n / 60000;
        if( min == 0 ) cout << "00:";
        else if( min < 10 ) cout << "0" << min << ":";
        else cout << min << ":";

        seg = n % 60000;
        if( seg > 999 ) {
            stringstream ss;
            ss << seg;
            string s = ss.str();
            s.erase( s.end()-3, s.end() );
            ss.str( s );
            ss >> seg;
        } else {
            seg = 0;
        }
        if( seg == 0 ) cout << "00:";
        else if( seg < 10 ) cout << "0" << seg << ":";
        else cout << seg << ":";

        mil = n % 1000;
        if( mil == 0 ) cout << "000" << endl;
        else if( mil < 10 ) cout << "00" << mil << endl;
        else if( mil < 100 ) cout << "0" << mil << endl;
        else cout << mil << endl;
    }
    return 0;
}

