#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int Part;
    cin >> Part;
    cin.ignore(1,'\n');
    for( int i = 0; i < Part; ++i ) {
        string p;
        getline( cin, p );
        stringstream ss(p);
        int A, B, SetsA = 0, SetsB = 0;
        char c;
        bool Valido = true;
        while( ss >> A >> c >> B ) {
            if( SetsA + SetsB < 2 ) {
                if( (A == 6 && B < 5) || (A == 7 && (B == 6 || B == 5) ) ) {
                    SetsA++;
                } else if( (B == 6 && A < 5) || (B == 7 && (A == 6 || A == 5) ) ) {
                    SetsB++;
                } else {
                    Valido = false;
                }
            } else {
                if( A > B && ( (A == 6 && A-B >= 2) || (A > 6 && A-B == 2) ) ) {
                    SetsA++;
                } else if( B > A && ( (B == 6 && B-A >= 2) || (B > 6 && B-A == 2) ) ) {
                    SetsB++;
                } else {
                    Valido = false;
                }
            }
        }
        if( SetsA == 2 && (SetsB == 1 || SetsB == 0) ) {}
        else if( SetsB == 2 && (SetsA == 1 || SetsA == 0) ) {}
        else Valido = false;
        if( (s1 == "federer" && SetsB > 0) || (s2 == "federer" && SetsA > 0) ) Valido = false;

        if( Valido ) cout << "yeah" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
