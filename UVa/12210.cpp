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
	int B, S, caso = 1;
	int age, i;
	multiset<int> Spinster;
	scanf("%d %d ", &B, &S);
	while (B > 0) {
		vector<int> Bachelor(B);
		Spinster.clear();
		// Read input data
		for (i = 0; i < B; ++i)
			scanf("%d ", &Bachelor[i]);
		for (i = 0; i < S; ++i) {
			scanf("%d ", &age);
			Spinster.insert(age);
		}
		sort(Bachelor.begin(), Bachelor.end(), greater<int>());
		// Make the pairs
		multiset<int>::iterator lower, prevlower;
		for (i = 0; i < B && !Spinster.empty(); ++i) {
			lower = Spinster.lower_bound(Bachelor[i]);
			if (lower == Spinster.begin()) {
				Spinster.erase(lower);
			} else {
				prevlower = lower;
				prevlower--;
				if (lower != Spinster.end() && abs(*lower - Bachelor[i]) < abs(*prevlower - Bachelor[i])) {
					Spinster.erase(lower);
				} else {
					Spinster.erase(prevlower);
				}
			}
		}
		// Output the result
		if (i < B) {
			printf("Case %d: %d %d\n", caso++, B - i, Bachelor[B - 1]);
		} else {
			printf("Case %d: 0\n", caso++);
		}

		scanf("%d %d ", &B, &S);
	}

	return 0;
}
