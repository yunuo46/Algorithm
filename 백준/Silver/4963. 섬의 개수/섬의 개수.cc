#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int w, h, num, ans;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1, 1,-1,1,-1};
bool maps[50][50];
bool visited[50][50];
queue<pair<int, int>> q;

void dfs(int x, int y) {
	if(maps[x][y]) visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[nx][ny] && maps[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (true) {
		cin >> w >> h;
		if (w == 0)break;

		ans = 0;
		// 초기화

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> num;
				if (num) {
					maps[j][i] = true;
					visited[j][i] = false;
					q.push(make_pair(j, i));
				}
				else maps[j][i] = false;
			}
		}
		while (!q.empty()) {
			int qx = q.front().first;
			int qy = q.front().second;
			if (!visited[qx][qy]) {
				dfs(qx, qy);
				ans++;
			}
			q.pop();
		}
		cout << ans << endl;
	}
}