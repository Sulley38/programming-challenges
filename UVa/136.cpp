#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
/*
	long long int menor;
	set<long long int> ugly;
	set<long long int>::iterator it;
	ugly.insert(1);

	while (ugly.size() < 1500) {
		menor = *ugly.rbegin() * 5;
		for (it = ugly.begin(); it != ugly.end(); it++) {
			if (ugly.find(*it * 2) == ugly.end() && *it * 2 < menor) {
				menor = *it * 2;
				break;
			} else if (ugly.find(*it * 3) == ugly.end() && *it * 3 < menor) {
				menor = *it * 3;
			} else if (ugly.find(*it * 5) == ugly.end() && *it * 5 < menor) {
				menor = *it * 5;
			}
		}
		ugly.insert(menor);
	}

	it = ugly.begin();
	for (int i = 0; i < 1500; ++i, ++it)
		cout << *it << endl;
	cout << endl;
*/
	puts("The 1500'th ugly number is 859963392.");

	return 0;
}
