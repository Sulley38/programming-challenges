#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string,string> Prot;
    Prot["UUU"] = "phe"; Prot["UUC"] = "phe"; Prot["UUA"] = "leu"; Prot["UUG"] = "leu";
    Prot["UCU"] = "ser"; Prot["UCC"] = "ser"; Prot["UCA"] = "ser"; Prot["UCG"] = "ser";
    Prot["UAU"] = "tyr"; Prot["UAC"] = "tyr"; Prot["UAA"] = "STOP"; Prot["UAG"] = "STOP";
    Prot["UGU"] = "cys"; Prot["UGC"] = "cys"; Prot["UGA"] = "STOP"; Prot["UGG"] = "trp";
    Prot["CUU"] = "leu"; Prot["CUC"] = "leu"; Prot["CUA"] = "leu"; Prot["CUG"] = "leu";
    Prot["CCU"] = "pro"; Prot["CCC"] = "pro"; Prot["CCA"] = "pro"; Prot["CCG"] = "pro";
    Prot["CAU"] = "his"; Prot["CAC"] = "his"; Prot["CAA"] = "gln"; Prot["CAG"] = "gln";
    Prot["CGU"] = "arg"; Prot["CGC"] = "arg"; Prot["CGA"] = "arg"; Prot["CGG"] = "arg";
    Prot["AUU"] = "ile"; Prot["AUC"] = "ile"; Prot["AUA"] = "ile"; Prot["AUG"] = "met";
    Prot["ACU"] = "thr"; Prot["ACC"] = "thr"; Prot["ACA"] = "thr"; Prot["ACG"] = "thr";
    Prot["AAU"] = "asn"; Prot["AAC"] = "asn"; Prot["AAA"] = "lys"; Prot["AAG"] = "lys";
    Prot["AGU"] = "ser"; Prot["AGC"] = "ser"; Prot["AGA"] = "arg"; Prot["AGG"] = "arg";
    Prot["GUU"] = "val"; Prot["GUC"] = "val"; Prot["GUA"] = "val"; Prot["GUG"] = "val";
    Prot["GCU"] = "ala"; Prot["GCC"] = "ala"; Prot["GCA"] = "ala"; Prot["GCG"] = "ala";
    Prot["GAU"] = "asp"; Prot["GAC"] = "asp"; Prot["GAA"] = "glu"; Prot["GAG"] = "glu";
    Prot["GGU"] = "gly"; Prot["GGC"] = "gly"; Prot["GGA"] = "gly"; Prot["GGG"] = "gly";
    string s, Total, Cad, Res;
    while( getline( cin, s ) ) Total += s;

    int Ind = 0, Tam = Total.size();
    while( Ind+3 <= Tam ) {
        Cad = Total.substr( Ind, 3 );
        if( Res == "" && Cad == "AUG" ) {
            Res = "met";
            Ind += 3;
        } else if( Res != "" && Prot[Cad] == "STOP" ) {
            cout << Res << endl;
            Res = "";
            Ind += 3;
        } else if( Res != "" && Prot.count( Cad ) > 0 ) {
            Res += "-" + Prot[Cad];
            Ind += 3;
        } else {
            Ind++;
        }
    }
    if( Res != "" ) cout << "ERROR" << endl;
    return 0;
}
