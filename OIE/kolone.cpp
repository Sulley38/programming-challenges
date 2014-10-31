#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H1, H2;
    cin >> H1 >> H2;

    vector< pair<char,bool> > Col(H1+H2); //False = izquierda, true = derecha
    for( int i = H1-1; i >= 0; i-- ) {
        cin >> Col[i].first;
        Col[i].second = true;
    }
    for( int i = H1; i < H1+H2; i++ ) {
        cin >> Col[i].first;
        Col[i].second = false;
    }

    int N;
    cin >> N;
    while( N-- ) {
        for( int i = 0; i < H1+H2; i++ ) {
            if( Col[i].second ) {
                if( i < H1+H2-1 && Col[i].second != Col[i+1].second ) {
                    swap( Col[i], Col[i+1] );
                    i++;
                    if( !Col[i+1].second ) i++;
                }
            } else {
                if( i > 0 && Col[i].second != Col[i-1].second ) {
                    swap( Col[i], Col[i-1] );
                    if( !Col[i+1].second ) i++;
                }
            }
        }
    }

    for( int i = 0; i < H1+H2; i++ ) cout << Col[i].first;
    cout << endl;
    return 0;
}
