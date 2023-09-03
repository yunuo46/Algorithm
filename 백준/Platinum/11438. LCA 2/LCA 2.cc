#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 18
using namespace std;

vector<vector<int>> tree;
int parent[100001][MAX];
int depth[100001];
int n, from, to, m, u, v = 0;

void dfs(int cur) {
	for (int next : tree[cur]) {
		if (depth[next] == -1) {
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			dfs(next);
		}
	}
}

void connect() {
	for (int i = 1; i < MAX; i++)
		for (int cur = 1; cur <= n; cur++)
			parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int dep = depth[u] - depth[v];
	for (int i = 0; dep > 0; i++) {
		if (dep % 2 == 1) u = parent[u][i];
		dep = dep >> 1;
	}

	if (u != v) {
		for (int i = MAX - 1; i >= 0; i--) {
			if (parent[u][i] && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	tree.resize(n + 1);
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	depth[1] = 0;

	for (int i = 0; i < n - 1; i++) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	dfs(1);
	connect();

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << LCA(u, v) << endl;
	}
	return 0;
}
