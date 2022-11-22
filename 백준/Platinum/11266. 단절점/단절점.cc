#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
#define endl "\n"
using namespace std;

int n, m, dfn = 0;
vector<int> Edges[100001];
vector<int> Type[100001];
int Dfn[100001];
int L[100001];
int Cut[100001];

void dfs(int x, int p) {
	int i, s;
	Dfn[x] = ++dfn;
	s = Edges[x].size();
	for (i = 0; i < s; i++) {
		if (Edges[x][i] == p) {
			Type[x][i] = 1;
		}
		else if (Dfn[Edges[x][i]] == 0) {
			Type[x][i] = 2;
			dfs(Edges[x][i], x);
		}
		else {
			Type[x][i] = 3;
		}
	}
}

int dfs2(int x, int p) {
	int i, s, rv, cc;
	L[x] = Dfn[x];
	s = Edges[x].size();
	for (i = 0; i < s; i++) {
		if (Type[x][i] == 1) {}
		else if (Type[x][i] == 2) {
			rv = dfs2(Edges[x][i], x);
			L[x] = min(L[x], rv);
		}
		else
			L[x] = min(L[x], Dfn[Edges[x][i]]);
	}

	if (p == 0) {
		cc = 0;
		for (i = 0; i < s; i++)
			if (Type[x][i] == 2)
				cc++;
		if (cc > 1)
			Cut[x] = 1;
	}
	else {
		for (i = 0; i < s; i++) {
			if (Type[x][i] == 2) {
				if (L[Edges[x][i]] >= Dfn[x])
					Cut[x] = 1;
			}
		}
	}
	return L[x];
}

int32_t main() {
	int i, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		Edges[x].push_back(y);
		Type[x].push_back(0);
		Edges[y].push_back(x);
		Type[y].push_back(0);
	}
	for (i = 1; i <= n; i++) {
		dfs(i, 0);
		dfs2(i, 0);
	}
	vector<int> ans;
	for (i = 1; i <= n; i++) {
		if (Cut[i] == 1) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}