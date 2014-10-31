#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> period(3001), count(3001, 1);

struct comp {
	bool operator() (const int &a, const int &b) {
		if (period[a] * count[a] == period[b] * count[b])
			return a > b;
		return period[a] * count[a] > period[b] * count[b];
	}
};

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s;
	int id, p, k;
	priority_queue<int, vector<int>, comp> cola;

	while (cin >> s && s != "#") {
		cin >> id >> p;
		period[id] = p;
		cola.push(id);
	}

	cin >> k;
	while (k--) {
		id = cola.top();
		cola.pop();
		cout << id << endl;
		count[id]++;
		cola.push(id);
	}

	return 0;
}
