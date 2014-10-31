#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
string s;
int tam;

bool Compara( const int& a, const int& b )
{
    int i = a, j = b;
    if( a == b ) return false;
    while( s[i] == s[j] ) {
        i++; j++;
        if( i == tam || j == tam ) return a > b;
    }
    return s[i] < s[j];
}

int main()
{
    cin >> s;
    tam = s.size();
    vector<int> Index( tam );
    for( int i = 0; i < tam; i++ ) Index[i] = i;

    sort( Index.begin(), Index.end(), Compara );
    for( int i = 0; i < tam-1; i++ ) cout << Index[i] << " ";
    cout << Index[tam-1] << "." << endl;
    return 0;
}
