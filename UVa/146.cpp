#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s;
	while (getline(cin, s) && s != "#") {
		if (next_permutation(s.begin(), s.end()))
			puts(s.data());
		else
			puts("No Successor");
	}

	return 0;
}
