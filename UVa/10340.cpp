#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	unsigned int i, j;
	string s, t;
	while (cin >> s >> t) {
		for (i = j = 0; i < t.size(); ++i) {
			if (s[j] == t[i]) {
				j++;
				if (j == s.size())
					i = t.size();
			}
		}
		cout << (j == s.size() ? "Yes" : "No") << endl;
	}
	return 0;
}
