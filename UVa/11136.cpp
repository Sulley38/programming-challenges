#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, k, b;
	long long int cost;
	multiset<int> bill;
	multiset<int>::iterator ultimo;
	while (scanf("%d ", &n) > 0 && n != 0) {
		cost = 0;
		bill.clear();
		while (n--) {
			scanf("%d ", &k);
			while (k--) {
				scanf("%d ", &b);
				bill.insert(b);
			}
			ultimo = bill.end();
			ultimo--;
			cost += *ultimo - *bill.begin();
			bill.erase(ultimo);
			bill.erase(bill.begin());
		}
		printf("%lld\n", cost);
	}

	return 0;
}
