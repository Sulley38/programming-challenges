#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int iHora = 0, iMinuto = 0;

    while( cin >> iHora >> iMinuto ) {

        if( iMinuto != 0 and iMinuto != 15 and iMinuto != 30 and iMinuto != 45 ) {
            string ProxHora;
            stringstream ss;
            if( iMinuto > 45 ) {

                if( iHora == 23 ) {
                    ProxHora.append( "00" );
                } else if ( iHora < 9 ) {
                    iHora += 1;
                    ss << "0" << iHora;
                    ProxHora.append( ss.str() );
                } else {
                    iHora += 1;
                    ss << iHora;
                    ProxHora.append( ss.str() );
                }
                ProxHora.append( ":00" );

            } else {

                if( iHora < 10 ) {
                    ss << "0" << iHora;
                } else {
                    ss << iHora;
                }
                ProxHora.append( ss.str() );
                if( iMinuto > 30 )
                    ProxHora.append( ":45" );
                else if( iMinuto > 15 )
                    ProxHora.append( ":30" );
                else
                    ProxHora.append( ":15" );

            }
            cout << "silencio hasta las " << ProxHora << endl;
        } else {

            switch( iMinuto ) {
            case 0:
                cout << "ding ding ding ding";
                if( iHora > 12 )
                    iHora -= 12;
                else if( iHora == 0 )
                    iHora = 12;
                for( int h = 0; h < iHora; h++ ) {
                    cout << " dong";
                }
                cout << endl;
              break;
            case 15:
                cout << "ding" << endl;
              break;
            case 30:
                cout << "ding ding" << endl;
              break;
            case 45:
                cout << "ding ding ding" << endl;
              break;
            }

        }
    }

    return 0;
}
