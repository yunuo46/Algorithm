#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int a, b, n, m, ans = 0;
bool visited[1001];
stack<int>s[1001];

void dfs(int idx) {
	visited[idx] = true;
	while (!s[idx].empty()) {
		int next = s[idx].top();
		s[idx].pop();
		dfs(next);
	}
}

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s[a].push(b);
		s[b].push(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}