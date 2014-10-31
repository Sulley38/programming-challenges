#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string a, b, x;
    while( getline(cin,a) ) {
        getline(cin,b);
        vector<int> Presente(26);
        for( int i = 0; i < int(a.size()); ++i )
            Presente[a[i]-'a']++;
        for( int i = 0; i < int(b.size()); ++i ) {
            if( Presente[b[i]-'a'] > 0 ) {
                x.push_back(b[i]);
                Presente[b[i]-'a']--;
            }
        }
        // Ordenar alfabeticamente y mostrar
        sort( x.begin(), x.end() );
        cout << x << endl;
        x.clear();
    }

    return 0;
}
