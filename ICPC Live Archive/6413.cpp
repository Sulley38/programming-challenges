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
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vll;

#define INVALID (1LL << 63)

char inverso(char op) {
	if (op == '+') return '-';
    if (op == '-') return '+';
    if (op == '*') return '/';
    return '*';
}

ll operar(ll a, char op, ll b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int N;
    string line;
    char letra, operando1, operando2, operacion;
    int val, valcount;
    cin >> N;
    cin.ignore();
    while (N--) {
        vll value(26, INVALID);
        vi op1(26), op2(26);
        vector<char> ops(26);
        valcount = 0;
        for (int i = 0; i < 26; ++i) {
            getline(cin, line);
            stringstream ss(line);
            val = -1;
            ss >> letra >> operando1 >> operacion >> operando2 >> val;
            op1[letra-'A'] = operando1 - 'A';
            ops[letra-'A'] = operacion;
            op2[letra-'A'] = operando2 - 'A';
            if (val > 0) {
                value[letra-'A'] = val;
                valcount++;
            }
        }

        while (valcount < 26) {
            for (int i = 0; i < 26; ++i) {
                if (value[i] == INVALID && value[op1[i]] != INVALID && value[op2[i]] != INVALID) {
                    value[i] = operar(value[op1[i]], ops[i], value[op2[i]]);
                    valcount++;
                } else if (value[op1[i]] == INVALID && value[i] != INVALID && value[op2[i]] != INVALID) {
                	value[op1[i]] = operar(value[i], inverso(ops[i]), value[op2[i]]);
                	valcount++;
                } else if (value[op2[i]] == INVALID && value[i] != INVALID && value[op1[i]] != INVALID) {
                	if (ops[i] == '+' || ops[i] == '*')
                		value[op2[i]] = operar(value[i], inverso(ops[i]), value[op1[i]]);
                	else
                		value[op2[i]] = operar(value[op1[i]], ops[i], value[i]);
                	valcount++;
                } else if (i == op1[i] && i == op2[i] && value[i] == INVALID) {
                	if (ops[i] == '+' || ops[i] == '-')
                		value[i] = 0;
                	else
                		value[i] = 1;
                	valcount++;
            	} else if (i == op1[i] && value[op2[i]] == INVALID) {
                	if (ops[i] == '+' || ops[i] == '-')
                		value[op2[i]] = 0;
                	else
                		value[op2[i]] = 1;
                	valcount++;
                } else if (i == op2[i]) {
                	if (ops[i] == '+' && value[op1[i]] == INVALID) {
                		value[op1[i]] = 0;
                		valcount++;
                	} else if (ops[i] == '*' && value[op1[i]] == INVALID) {
                		value[op1[i]] = 1;
                		valcount++;
                	} else if (ops[i] == '-' && value[i] == INVALID && value[op1[i]] != INVALID) {
                		value[i] = value[op1[i]] / 2;
                		valcount++;
                	} else if (ops[i] == '-' && value[op1[i]] == INVALID && value[i] != INVALID) {
                		value[op1[i]] = 2 * value[i];
                		valcount++;
                	} else if (ops[i] == '/' && value[i] == INVALID && value[op1[i]] != INVALID) {
                		value[i] = sqrt(value[op1[i]]);
                		valcount++;
                	} else if (ops[i] == '/' && value[op1[i]] == INVALID && value[i] != INVALID) {
                		value[op1[i]] = value[i] * value[i];
                		valcount++;
                	}
                }
            }
        }

        cout << value[0];
        for (int i = 1; i < 26; ++i)
            cout << " " << value[i];
        cout << endl;
    }

}
