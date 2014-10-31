#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, command, value, result;
	while (scanf("%d ", &n) > 0) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		result = 0;

		while (n--) {
			scanf("%d %d ", &command, &value);
			if (command == 1) {
				s.push(value);
				q.push(value);
				pq.push(value);
			} else {
				if (s.empty()) {
					result = 7;
				} else {
					if (s.top() != value)
						result |= 1;
					if (q.front() != value)
						result |= 2;
					if (pq.top() != value)
						result |= 4;
					s.pop();
					q.pop();
					pq.pop();
				}
			}
		}

		if (result == 3)
			puts("priority queue");
		else if (result == 5)
			puts("queue");
		else if (result == 6)
			puts("stack");
		else if (result == 7)
			puts("impossible");
		else
			puts("not sure");
	}

	return 0;
}
