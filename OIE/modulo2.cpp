#include <iostream>
#include <map>

using namespace std;

int main()
{
    long long N, X;
    cin >> N;
    int Res = 0;
    map<long long, bool> Repetido;
    while( cin >> X ) {
        if( !Repetido[X%N] ) {
            Repetido[X%N] = true;
            Res++;
        }
    }
    cout << Res << endl;
    return 0;
}
