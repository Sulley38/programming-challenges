#include <algorithm>
#include <bitset>
#include <cmath>
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

bool close(const string &a, const string &b) {
	int m = a.size(), n = b.size(), diff = 0;
	if (m == n) {
		for (int i = 0; i < m; ++i)
			if (a[i] != b[i]) {
				if (diff) return false;
				diff = 1;
			}
		return (diff == 1);
	}
	if (m == n + 1) {
		for (int i = 0; i < n; ++i)
			if (a[i+diff] != b[i]) {
				if (diff) return false;
				diff = 1, i--;
			}
		return true;
	}
	if (m + 1 == n) {
		for (int i = 0; i < m; ++i)
			if (a[i] != b[i+diff]) {
				if (diff) return false;
				diff = 1, i--;
			}
		return true;
	}
	return false;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s;
	vector<string> words;
	vector<int> longest;
	int i, n = 0, ans = 0;

 	while (cin >> s) {
 		words.push_back(s);
 		longest.push_back(1);
 		for (i = n - 1; i >= 0; --i)
 			if (longest[i] + 1 > longest[n] && close(s, words[i]))
 				longest[n] = longest[i] + 1;
 		n++;
	}

 	for (i = 0; i < n; ++i)
 		ans = max(ans, longest[i]);
 	cout << ans << endl;

	return 0;
}
