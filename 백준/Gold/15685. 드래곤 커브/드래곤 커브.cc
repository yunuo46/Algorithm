#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 18
using namespace std;
int n, x, y, d, g, ans = 0;
queue <pair<pair<int, int>, int>> q;
bool board[101][101];
int cnt = 0;
int tempx, tempy;

void dragon_curve(int x, int y, int g, int cur) {
	if (cur > g) {
		while (!q.empty()) {
			int nx = q.front().first.first;
			int ny = q.front().first.second;
			int nz = q.front().second;
			q.pop();
			if (nz == 0) {
				if (nx > 0 && nx <= 100 && ny >= 0 && ny <= 100) {
					board[nx - 1][ny] = true;
					board[nx][ny] = true;
					//cout << nx << " " << ny << " " << nz << endl;
				}
			}
			else {
				if (nx >= 0 && nx <= 100 && ny > 0 && ny <= 100) {
					board[nx][ny-1] = true;
					board[nx][ny] = true;
					//cout << nx << " " << ny << " " << nz << endl;
				}
			}
		}
		return;
	}
	for (int i = 0; i < pow(2, cur - 1); i++) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int nz = q.front().second;
		q.pop();
		q.push({ {nx, ny}, nz });
		// 시계방향 회전 : (nx,ny) => (x+(y-ny),y+(nx-x))
		if (nz == 0) {
			q.push({ {x + y - ny,y - x + nx},1 });
			if (i == 0) {
				//cout << x << " " << y << endl;
				tempx = x + y - ny;
				tempy = y - x + nx - 1;
				if (d == 1)tempy++;
			}
		}
		else {
			q.push({ {x + y - ny + 1,y - x + nx},0 });
			if (i == 0) {
				//cout << x << " " << y << endl;
				tempx = x + y - ny;
				if (d == 2)tempx++;
				tempy = y - x + nx;
			}
		}
	}
	//cout << d << endl;
	x = tempx;
	y = tempy;
	//cout << x << " " << y << endl;
	dragon_curve(x, y, g, cur + 1);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> x >> y >> d >> g;
		switch (d) {
		case 0:
			x += 1;
			q.push({ {x, y}, 0 });
			d = 1;
			break;
		case 1:
			q.push({ {x, y}, 1 });
			y -= 1;
			d = 2;
			break;
		case 2:
			q.push({ {x, y}, 0 });
			x -= 1;
			d = 3;
			break;
		case 3:
			y += 1;
			q.push({ {x , y}, 1 });
			d = 0;
			break;
		}
		// 0세대 커브
		if (g > 0) {
			switch (d) {
			case 0:
				x += 1;
				q.push({ {x, y}, 0 });
				d = 2;
				break;
			case 1:
				q.push({ {x, y}, 1 });
				y -= 1;
				d = 3;
				break;
			case 2:
				q.push({ {x, y}, 0 });
				x -= 1;
				d = 0;
				break;
			case 3:
				y += 1;
				q.push({ {x , y}, 1 });
				d = 1;
				break;
			}
		}
		// 1세대 커브
		dragon_curve(x, y, g, 2);
		// 2세대 이상 커브 (d가 변하지 않는 패턴 시작)
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) {
				ans++;
				//cout << i << " " << j << endl;
			}
		}
	}
	cout << ans;
	return 0;
}
