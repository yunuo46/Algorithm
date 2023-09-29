#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int v, e, dfn;
vector<int> Edges[10001];
stack<int> s;
bool finished[10001];
vector<vector<int>> SCC;
int Dfn[10001];

int dfs(int x) {
	Dfn[x] = ++dfn;
	s.push(x);
	int p = Dfn[x];
	for (int i = 0; i < Edges[x].size(); i++) {
		int y = Edges[x][i];
		//cout << y << endl;
		// 4 5 1 6 7 3 7 2 7
		if (Dfn[y] == 0) p = min(p, dfs(y)); // 방문X
		else if (!finished[y]) p = min(p, Dfn[y]); // 처리 중
		//cout << y << " " << p << " " << Dfn[y] << endl;
	}
	//cout << x << " " << p << " " << Dfn[x] << endl;
	if (p == Dfn[x]) {
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x)break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return p;
}

int main() {
	int i, x, y;
	cin >> v >> e;
	for (i = 0; i < e; i++) {
		cin >> x >> y;
		Edges[x].push_back(y);
	}
	for (i = 1; i <= v; i++) {
		if (Dfn[i] == 0) dfs(i);
	}
	cout << SCC.size() << endl;
	sort(SCC.begin(), SCC.end());
	for (i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << "-1" << endl;
	}
	return 0;
}