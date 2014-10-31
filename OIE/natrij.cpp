#include <iostream>

using namespace std;

int main()
{
    int H1, M1, S1, H2, M2, S2;
    char p;
    cin >> H1 >> p >> M1 >> p >> S1;
    cin >> H2 >> p >> M2 >> p >> S2;

    if( H1 == H2 && M1 == M2 && S1 == S2 ) {
        cout << "24:00:00" << endl;
    } else {
        int RH, RM, RS;
        if( S1 > S2 ) {
            RS = S2+60-S1;
            M2--;
            if( M2 < 0 ) {
                M2 = 59; H2--;
            }
        } else {
            RS = S2-S1;
        }
        if( M1 > M2 ) {
            RM = M2+60-M1;
            H2--;
            if( H2 < 0 )
                H2 = 23;
        } else {
            RM = M2-M1;
        }
        if( H1 > H2 ) {
            RH = H2+24-H1;
        } else
            RH = H2-H1;

        if( RH < 10 ) cout << "0" << RH << ":";
        else cout << RH << ":";
        if( RM < 10 ) cout << "0" << RM << ":";
        else cout << RM << ":";
        if( RS < 10 ) cout << "0" << RS << endl;
        else cout << RS << endl;
    }

    return 0;
}
