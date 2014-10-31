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
	int dp[14][14][14];
	memset(dp, 0, sizeof dp);
	dp[1][1][1] = 1;
	for (int i = 2; i < 14; ++i)
		for (int j = 1; j < 14; ++j)
			for (int k = 1; k < 14; ++k)
				dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);

	int T, N, P, R;
	cin >> T;
	while (T--) {
		cin >> N >> P >> R;
		cout << dp[N][P][R] << endl;
	}

	return 0;
}
