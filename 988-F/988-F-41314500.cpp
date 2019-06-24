// nice one
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {

	
	int a, n, m;
	cin >> a >> n >> m;
	vector<int> rain(a + 1);
	vector<pair<int, int> > umb(a + 1, make_pair(INF, -1));
	vector<int> costs(m);
	
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		for (int j = l; j < r; ++j)
			rain[j] = 1;
	}
	
	for (int i = 0; i < m; ++i) {
		int x, p;
		cin >> x >> p;
		costs[i] = p;
		umb[x] = min(umb[x], make_pair(p, i));
	}
	
	vector<vector<int> > dp(a + 1, vector<int>(m + 1, INF));
	dp[0][m] = 0; // no umbrealla 
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i][j] == INF)
				continue;
			if (rain[i] == 0) 
				dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
			if (j < m) 
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[j]);
			if (umb[i].first != INF)
				dp[i + 1][umb[i].second] = min(dp[i + 1][umb[i].second], dp[i][j] + umb[i].first);
		}
	}
	
	int ans = INF;
	for (int i = 0; i <= m; ++i)
		ans = min(ans, dp[a][i]);
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	
	return 0;
}