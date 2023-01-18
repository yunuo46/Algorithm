#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, num, ans_row, ans_col = 0;
char c;
bool m[101][101];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'X') m[i][j] = true;
		}
	}
	int row, col;
	bool state;
	for (int i = 0; i < n; i++) {
		state = false;
		row = 0;
		for (int j = 0; j < n; j++) {
			if (m[i][j]) {
				row = 0;
				state = false;
				continue;
			}
			if (state)continue;
			row++;
			if (row > 1) {
				ans_row++;
				state = true;
			}
			//cout << row << endl;
		}
	}
	for (int j = 0; j < n; j++) {
		state = false;
		col = 0;
		for (int i = 0; i < n; i++) {
			if (m[i][j]) {
				col = 0;
				state = false;
				continue;
			}
			if (state)continue;
			col++;
			if (col > 1) {
				ans_col++;
				state = true;
			}
		}
	}

	cout << ans_row << " " << ans_col;
	return 0;
}
