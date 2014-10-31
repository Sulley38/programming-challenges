#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void euclidesExt(const int a, const int b, int &x, int &y, int &mcd) {
	vector<int> r, s, t;
	r.push_back(a); r.push_back(b); s.push_back(1); s.push_back(0); t.push_back(0); t.push_back(1);
	int i = 1, q;
	while (r[i] != 0) {
		q = r[i-1] / r[i];
		r.push_back(r[i-1] % r[i]);
		s.push_back(s[i-1] - q*s[i]);
		t.push_back(t[i-1] - q*t[i]);
		i++;
	}
	mcd = r[i-1]; x = s[i-1]; y = t[i-1];
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int A, B, X, Y, D;
	while (cin >> A >> B) {
		euclidesExt(A,B,X,Y,D);
		cout << X << " "<< Y << " "<< D << endl;
	}

	return 0;
}
