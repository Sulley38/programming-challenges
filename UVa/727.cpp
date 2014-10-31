#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	char c = 1;
	stack<char> pila;

	scanf("%d ", &n);
	while (n--) {
		// Shunting-yard algorithm
		c = getchar();
		while (c != '\n' && c != EOF) {
			if (c == '+' || c == '-') {
				while (!pila.empty() && pila.top() != '(') {
					putchar(pila.top());
					pila.pop();
				}
				pila.push(c);
			} else if (c == '*' || c == '/') {
				while (!pila.empty() && (pila.top() == '*' || pila.top() == '/')) {
					putchar(pila.top());
					pila.pop();
				}
				pila.push(c);
			} else if (c == '(') {
				pila.push(c);
			} else if (c == ')') {
				while (pila.top() != '(') {
					putchar(pila.top());
					pila.pop();
				}
				pila.pop();
			} else {
				putchar(c);
			}

			c = getchar();
			c = getchar();
		}

		while (!pila.empty()) {
			putchar(pila.top());
			pila.pop();
		}

		putchar('\n');
		if (n > 0)
			putchar('\n');
	}

	return 0;
}
