#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int v, e, dfn;
stack<int> s;
vector<int> Edges[100001];
bool finished[100001];
vector<vector<int>> SCC;
int Dfn[100001];
int pid[100001];
bool isRoot[100001];

int dfs(int x) {
	Dfn[x] = ++dfn;
	s.push(x);
	int p = Dfn[x];
	for (int i = 0; i < Edges[x].size(); i++) {
		int y = Edges[x][i];
		if (Dfn[y] == 0) p = min(p, dfs(y)); // 방문X
		else if (!finished[y]) p = min(p, Dfn[y]); // 처리 중
	}
	if (p == Dfn[x]) {
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			pid[t] = x; // 그룹 번호 저장(pid)
			if (t == x)break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return p;
}

int main() {
	int t, i, x, y, ans;
	cin >> t;
	while (t--) {
		cin >> v >> e;

		// 초기화
		memset(isRoot, true, sizeof(isRoot));
		memset(finished, false, sizeof(finished));
		memset(Dfn, 0, sizeof(Dfn));
		memset(pid, 0, sizeof(pid));
		dfn = 0;
		ans = 0;
		SCC.clear();
		for (int i = 0; i < 100001; i++) {
			Edges[i].clear();
		}

		for (i = 0; i < e; i++) {
			cin >> x >> y;
			Edges[x].push_back(y);
		}
		for (i = 1; i <= v; i++) {
			if (Dfn[i] == 0) dfs(i);
		}
		for (i = 1; i <= v; i++) {
			for (int j = 0; j < Edges[i].size(); j++) {
				int y = Edges[i][j];
				if (pid[i] != pid[y]) isRoot[pid[y]] = false;
			}
		}
		for (i = SCC.size()-1; i >= 0; i--) {
			if (isRoot[pid[SCC[i][0]]]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}