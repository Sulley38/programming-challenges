#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

// Restar a la hora H1 la hora H2
int Restar( const int& H1, const int& H2 ) {
	int resta = H1-H2;
	if( H1 % 100 < H2 % 100 )
		resta -= 40;
	return (resta/100)*60 + resta%100;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int s, day = 1, h1, m1, h2, m2;
	string cita;
	while( cin >> s ) {
		vector<PII> Citas(s+2);

		Citas[0].first = 959;
		Citas[0].second = 1000;
		for( int i = 1; i < s+1; ++i ) {
			cin >> h1; cin.ignore();
			cin >> m1; cin.ignore();
			cin >> h2; cin.ignore();
			cin >> m2;
			Citas[i].first = h1*100 + m1;
			Citas[i].second = h2*100 + m2;
			cin.ignore(256,'\n');
		}
		Citas[s+1].first = 1800;
		Citas[s+1].second = 1801;

		sort( Citas.begin(), Citas.end() );

		int maxcomienzo, maxduracion = 0, resta;
		// Calcular tiempos
		for( int i = 0; i < s+1; ++i ) {
			resta = Restar(Citas[i+1].first, Citas[i].second);
			if( resta > maxduracion ) {
				maxcomienzo = Citas[i].second;
				maxduracion = resta;
			}
		}

		// Imprime el resultado
		cout << "Day #" << day << ": the longest nap starts at " << maxcomienzo/100 << ":";
		if( maxcomienzo%100 < 10 ) cout << "0";
		cout << maxcomienzo%100 << " and will last for ";
		if( maxduracion < 60 )
			cout << maxduracion << " minutes." << endl;
		else
			cout << maxduracion/60 << " hours and " << maxduracion%60 << " minutes." << endl;

		day++;
	}

	return 0;
}
