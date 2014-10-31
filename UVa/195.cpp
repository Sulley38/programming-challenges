#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

struct comp {
	bool operator() (const string &a, const string &b) const {
		for (unsigned int i = 0; i < a.size(); i++)
			if (tolower(a[i]) < tolower(b[i]))
				return true;
			else if (tolower(a[i]) > tolower(b[i]))
				return false;
			else if (isupper(a[i]) && islower(b[i]))
				return true;
			else if (islower(a[i]) && isupper(b[i]))
				return false;
		return false;
	}
};

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n;
	cin >> n;
	string s;
	set<string, comp> anagrams;
	while (n--) {
		anagrams.clear();
		cin >> s;
		sort(s.begin(), s.end());
		anagrams.insert(s);
		while (next_permutation(s.begin(), s.end()))
			anagrams.insert(s);
		for (set<string>::iterator it = anagrams.begin(); it != anagrams.end(); it++)
			cout << *it << endl;
	}

	return 0;
}
