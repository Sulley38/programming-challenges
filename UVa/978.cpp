#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n, fields, sgreen, sblue, i, power;
	multiset<int, greater<int> > green, blue;
	vector<int> nextgreen, nextblue;
	cin >> n;
	while (n--) {
		cin >> fields >> sgreen >> sblue;
		green.clear();
		blue.clear();
		// Introducir soldados
		for (i = 0; i < sgreen; ++i) {
			cin >> power;
			green.insert(power);
		}
		for (i = 0; i < sblue; ++i) {
			cin >> power;
			blue.insert(power);
		}
		// Simular batallas
		while (green.size() != 0 && blue.size() != 0) {
			for (i = 0; i < fields && int(green.size()) > 0 && int(blue.size()) > 0; ++i) {
				if (*green.begin() > *blue.begin())
					nextgreen.push_back((*green.begin())-(*blue.begin()));
				else if (*blue.begin() > *green.begin())
					nextblue.push_back((*blue.begin())-(*green.begin()));
				green.erase(green.begin());
				blue.erase(blue.begin());
			}
			for (i = 0; i < int(nextgreen.size()); ++i)
				green.insert(nextgreen[i]);
			nextgreen.clear();
			for (i = 0; i < int(nextblue.size()); ++i)
				blue.insert(nextblue[i]);
			nextblue.clear();
		}
		// Imprimir ganador
		if (green.size() > 0) {
			cout << "green wins" << endl;
			for (multiset<int, greater<int> >::iterator itgreen = green.begin(); itgreen != green.end(); ++itgreen)
				cout << *itgreen << endl;
		} else if (blue.size() > 0) {
			cout << "blue wins" << endl;
			for (multiset<int, greater<int> >::iterator itblue = blue.begin(); itblue != blue.end(); ++itblue)
				cout << *itblue << endl;
		} else {
			cout << "green and blue died" << endl;
		}
		if (n > 0)
			cout << endl;
	}

	return 0;
}
