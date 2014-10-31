#include <iostream>

using namespace std;

int main()
{
    int iMaxLength = 0, iMinLength = 1000;
    string Palabra, pSmaller = "zzzzz", pLarger;
    while( cin >> Palabra ) {
        if( int(Palabra.length()) > iMaxLength )
            iMaxLength = Palabra.length();
        if( int(Palabra.length()) < iMinLength )
            iMinLength = Palabra.length();
        if( Palabra < pSmaller )
            pSmaller = Palabra;
        if( Palabra > pLarger )
            pLarger = Palabra;
    }

    cout << iMinLength << endl;
    cout << iMaxLength << endl;
    cout << pSmaller << endl;
    cout << pLarger << endl;

    return 0;
}
