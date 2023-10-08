#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m, dfn = 1;
vector<int> Edges[500001];
stack<int> s;
int id[500001];
int cnt = 1;
int total[500001];
int dp[500001];
int money[500001];
vector<set<int>> scc;
int Dfn[500001];

int dfs(int x) {
	Dfn[x] = dfn;
	s.push(x);
	int p = Dfn[x];
	dfn++;
	for (int i = 0; i < Edges[x].size(); i++) {
		int y = Edges[x][i];
		if (Dfn[y] == 0) p = min(p, dfs(y));
		else if (!id[y]) p = min(p, Dfn[y]);
	}
	if (p == Dfn[x]) {
		while (true) {
			int t = s.top();
			s.pop();
			id[t] = cnt;
			total[cnt] += money[t];
			if (t == x)break;
		}
		cnt++;
	}
	return p;
}

int main() {
	int i, x, y, S, P;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> x >> y;
		Edges[x].push_back(y);
	}
	for (i = 1; i <= n; i++) {
		cin >> money[i];
	}
	cin >> S >> P;
	dfs(S);
	scc.resize(cnt + 1);
	for (i = 1; i <= n; i++) {
		//cout << i << " is " << Edges[i].size() << endl;
		for (int j = 0; j < Edges[i].size(); j++) {
			int x = Edges[i][j];
			//cout << x << " " << id[i] << id[x]<< scc[id[i]].size();
			if (id[i] && id[x] && (id[i] != id[x])) scc[id[i]].insert(id[x]);
		}
	}

	queue<int> q;
	q.push(id[S]);
	dp[id[S]] = total[id[S]];
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto it = scc[u].begin(); it != scc[u].end(); it++) {
			if (dp[*it] < dp[u] + total[*it]) {
				dp[*it] = dp[u] + total[*it];
				q.push(*it);
			}
		}
	}
	int ans = 0;
	while (P--) {
		cin >> x;
		ans = max(ans, dp[id[x]]);
	}
	cout << ans;
	return 0;
}