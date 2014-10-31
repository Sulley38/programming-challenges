#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool orden( const pair<int,float>& a, const pair<int,float>& b ) { return a.second > b.second; }

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int C;
	cin >> C;
	while( C-- ) {
		int n;
		cin >> n;

		vector< pair<int,float> > Ratios(n);
		float t, s;
		for( int i = 0; i < n; ++i ) {
			cin >> t >> s;
			Ratios[i].first = i+1;
			Ratios[i].second = s / t;
		}

		stable_sort( Ratios.begin(), Ratios.end(), orden );

		for( int i = 0; i < n-1; ++i )
			cout << Ratios[i].first << " ";
		cout << Ratios[n-1].first << endl;

		if( C > 0 )
			cout << endl;
	}

	return 0;
}
