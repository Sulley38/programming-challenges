#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string s1, s2;
    while( cin >> s1 >> s2 ) {
        sort( s1.begin(), s1.end() );
        sort( s2.begin(), s2.end() );

        int iLength = s1.length(), j = 0;
        for( int i = 0; i < iLength; i++ ) {
            size_t pos = s2.find_first_of( s1[j] );
            if( pos != string::npos ) {
                s1.erase( j, 1 );
                s2.erase( pos, 1 );
            } else {
                j++;
            }
        }

        int iCoste = s1.length() + s2.length();
        cout << iCoste << endl;
    }
    return 0;
}
