#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int r, c, dist, ans = 1;
char num;
int maps[21][21];
bool alpha[26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y, int dist) {
	ans = max(dist, ans);
	int now = maps[x][y] - 65;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int next = maps[nx][ny] - 65;
		if (nx >= 0 && nx < r && ny >= 0 && ny < c && !alpha[next]) {
			alpha[next] = true;
			dfs(nx, ny, dist + 1);
			alpha[next] = false;
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> num;
			maps[i][j] = (int)num;
		}
	}
	alpha[maps[0][0] - 65] = true;
	dfs(0, 0, 1);
	cout << ans;
}