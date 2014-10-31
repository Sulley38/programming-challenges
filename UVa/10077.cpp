#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Fraccion {
	int num, den;
};

bool mayor( const Fraccion& A, const Fraccion& B ) {
	return (A.num * B.den) > (B.num * A.den);
}

bool menor( const Fraccion& A, const Fraccion& B ) {
	return (A.num * B.den) < (B.num * A.den);
}

int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	struct Fraccion upper, lower, target, join;
	while (cin >> target.num >> target.den) {
		if (target.num == 1 && target.den == 1)
			break;

		upper.num = 1; upper.den = 0;
		lower.num = 0; lower.den = 1;

		bool found = false;
		string result;
		while (!found) {
			join.num = upper.num + lower.num; join.den = upper.den + lower.den;
			if (mayor(join, target)) {
				result.push_back('L');
				upper = join;
			} else if (menor(join, target)) {
				result.push_back('R');
				lower = join;
			} else {
				found = true;
			}
		}

		cout << result << endl;
	}

	return 0;
}
