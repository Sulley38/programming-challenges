#include <iostream>

using namespace std;

int main()
{
    int iRondas;
    cin >> iRondas;

    for( int a = 0; a < iRondas; a++ ) {
        int iMax;
        string conjetura, ganador;
        cin >> iMax >> conjetura >> ganador;
        cout << "ronda " << a+1 << endl;

        for( int iBernardo = 0; iBernardo <= iMax; iBernardo++ ) {
            for( int iAna = 0; iAna <= iMax; iAna++ ) {
                if( ganador == "Bernardo" ) {
                    if( conjetura == "pares" ) {
                        if( ( iBernardo + iAna ) % 2 == 0 )
                            cout << iBernardo << " " << iAna << endl;
                    } else {
                        if( ( iBernardo + iAna ) % 2 == 1 )
                            cout << iBernardo << " " << iAna << endl;
                    }
                } else {
                    if( conjetura == "pares" ) {
                        if( ( iBernardo + iAna ) % 2 == 1 )
                            cout << iBernardo << " " << iAna << endl;
                    } else {
                        if( ( iBernardo + iAna ) % 2 == 0 )
                            cout << iBernardo << " " << iAna << endl;
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;
}
