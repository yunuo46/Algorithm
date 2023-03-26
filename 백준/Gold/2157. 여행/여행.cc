#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, m, k, a, b, c, ans = 0;
map<pair<int, int>, int> mp;
int dp[301][301] = {0};
vector<int> nxt[301];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		if (a > b)continue;
		if (mp.find({a,b})!=mp.end()) {
			int tmp = mp[{a, b}];
			//cout << tmp;
			mp.erase({ a,b });
			mp.insert({ {a,b}, max(tmp,c) });
		}
		else {
			mp.insert({ {a,b}, c });
			nxt[a].push_back(b);
		}
	}

	for (int i = 0; i < nxt[1].size(); i++) {
		int next = nxt[1][i];
		int weight = mp[{1, next}];
		dp[next][2] = max(dp[next][2], weight);
	}

	for (int i = 2; i <= m; i++) {
		for (int cur = 1; cur <= n; cur++) {
			if (dp[cur][i] != 0) {
				for (int j = 0; j < nxt[cur].size(); j++) {
					int next = nxt[cur][j];
					int weight = mp[{cur, next}];
					dp[next][i + 1] = max(dp[next][i + 1], dp[cur][i] + weight);
				}
			}
		}
	}
	for (int i = 2; i <= m; i++) ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
}