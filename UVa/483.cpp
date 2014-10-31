#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
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
	string line, word;
	while (getline(cin, line)) {
		istringstream iss(line);
		iss >> word;
		cout << string(word.rbegin(), word.rend());
		while (iss >> word)
			cout << " " << string(word.rbegin(), word.rend());
		cout << endl;
	}

	return 0;
}
