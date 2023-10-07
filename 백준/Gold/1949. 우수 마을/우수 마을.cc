#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, w, u, v;
vector<int> tree[100001];
int dp[100001][2];
bool visited[100001];

void dfs(int now) {
	visited[now] = true;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (visited[next])continue;
		dfs(next);
		dp[now][0] += max(dp[next][0],dp[next][1]);
		dp[now][1] += dp[next][0];
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w;
		dp[i][1] = w;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1);
	cout << max(dp[1][1], dp[1][0]);
	return 0;
}