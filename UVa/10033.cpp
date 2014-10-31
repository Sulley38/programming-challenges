#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Casos;
    string s;
    cin >> Casos;
    cin.ignore(1);
    getline(cin,s);
    while( Casos-- ) {
        vector<int> Registro(10,0);
        vector<string> Instrucciones(1000,"000");
        // Lee las instrucciones una a una
        int Index = 0, Ejecutados = 0;
        while( getline(cin,s) && s != "" ) {
            Instrucciones[Index] = s;
            Index++;
        }
        // Procesa los comandos
        Index = 0;
        while( Index != -1 ) {
            if( Instrucciones[Index][0] == '1' ) {
                Index = -2;
            } else if( Instrucciones[Index][0] == '2' ) {
                Registro[Instrucciones[Index][1]-'0'] = Instrucciones[Index][2]-'0';
            } else if( Instrucciones[Index][0] == '3' ) {
                Registro[Instrucciones[Index][1]-'0'] += Instrucciones[Index][2]-'0';
                Registro[Instrucciones[Index][1]-'0'] %= 1000;
            } else if( Instrucciones[Index][0] == '4' ) {
                Registro[Instrucciones[Index][1]-'0'] *= Instrucciones[Index][2]-'0';
                Registro[Instrucciones[Index][1]-'0'] %= 1000;
            } else if( Instrucciones[Index][0] == '5' ) {
                Registro[Instrucciones[Index][1]-'0'] = Registro[Instrucciones[Index][2]-'0'];
            } else if( Instrucciones[Index][0] == '6' ) {
                Registro[Instrucciones[Index][1]-'0'] += Registro[Instrucciones[Index][2]-'0'];
                Registro[Instrucciones[Index][1]-'0'] %= 1000;
            } else if( Instrucciones[Index][0] == '7' ) {
                Registro[Instrucciones[Index][1]-'0'] *= Registro[Instrucciones[Index][2]-'0'];
                Registro[Instrucciones[Index][1]-'0'] %= 1000;
            } else if( Instrucciones[Index][0] == '8' ) {
                Registro[Instrucciones[Index][1]-'0'] = (Instrucciones[Registro[Instrucciones[Index][2]-'0']][0]-'0')*100 +
                (Instrucciones[Registro[Instrucciones[Index][2]-'0']][1]-'0')*10 + (Instrucciones[Registro[Instrucciones[Index][2]-'0']][2]-'0');
            } else if( Instrucciones[Index][0] == '9' ) {
                // Convertir valor a string
                string a;
                a.push_back( Registro[Instrucciones[Index][1]-'0']/100 +'0' );
                a.push_back( Registro[Instrucciones[Index][1]-'0']/10%10 +'0' );
                a.push_back( Registro[Instrucciones[Index][1]-'0']%10 +'0' );
                Instrucciones[Registro[Instrucciones[Index][2]-'0']] = a;
            } else if( Instrucciones[Index][0] == '0' && Registro[Instrucciones[Index][2]-'0'] != 0 ) {
                Index = Registro[Instrucciones[Index][1]-'0']-1;
            }

            Index++;
            Ejecutados++;
        }

        cout << Ejecutados << endl;
        if( Casos > 0 ) cout << endl;
    }

    return 0;
}
