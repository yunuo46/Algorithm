#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 500001
using namespace std;

vector<int> v;
int n, num, ans = 0;
int branch_cut[11];
int board[20][20];

void right() {
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = n - 1; j >= 0; j--) {
			if (board[i][j]) v.push_back(board[i][j]);
		}
		if (v.empty())continue;
		int cntZero = n - v.size();
		int idx = n - 1;
		int idxVec = 0;
		while (idxVec < v.size() - 1) {
			if (v[idxVec] == v[idxVec + 1]) {
				board[i][idx] = v[idxVec] * 2;
				ans = max(ans, board[i][idx]);
				cntZero++;
				idx--;
				idxVec += 2;
			}
			else {
				board[i][idx] = v[idxVec];
				idx--;
				idxVec++;
			}
		}
		if (idxVec == v.size() - 1)board[i][idx] = v[idxVec];
		for (int j = 0; j < cntZero; j++) {
			board[i][j] = 0;
		}
	}
}
void left() {
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = 0; j < n; j++) {
			if (board[i][j]) v.push_back(board[i][j]);
		}
		if (v.empty())continue;
		int cntZero = n - v.size();
		int idx = 0;
		int idxVec = 0;
		while (idxVec < v.size() - 1) {
			if (v[idxVec] == v[idxVec + 1]) {
				board[i][idx] = v[idxVec] * 2;
				ans = max(ans, board[i][idx]);
				cntZero++;
				idx++;
				idxVec += 2;
			}
			else {
				board[i][idx] = v[idxVec];
				idx++;
				idxVec++;
			}
		}
		if (idxVec == v.size() - 1)board[i][idx] = v[idxVec];
		for (int j = n - cntZero; j < n; j++) {
			board[i][j] = 0;
		}
	}
}
void up() {
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = 0; j < n; j++) {
			if (board[j][i]) v.push_back(board[j][i]);
		}
		if (v.empty())continue;
		int cntZero = n - v.size();
		int idx = 0;
		int idxVec = 0;
		while (idxVec < v.size() - 1) {
			//cout << i << " " << idxVec << endl;
			if (v[idxVec] == v[idxVec + 1]) {
				board[idx][i] = v[idxVec] * 2;
				ans = max(ans, board[idx][i]);
				cntZero++;
				idx++;
				idxVec += 2;
			}
			else {
				board[idx][i] = v[idxVec];
				idx++;
				idxVec++;
			}
		}
		if (idxVec == v.size() - 1)board[idx][i] = v[idxVec];
		for (int j = n - cntZero; j < n; j++) {
			board[j][i] = 0;
		}
	}
}
void down() {
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = n - 1; j >= 0; j--) {
			if (board[j][i]) v.push_back(board[j][i]);
		}
		if (v.empty())continue;
		int cntZero = n - v.size();
		int idx = n - 1;
		int idxVec = 0;
		while (idxVec < v.size() - 1) {
			if (v[idxVec] == v[idxVec + 1]) {
				board[idx][i] = v[idxVec] * 2;
				ans = max(ans, board[idx][i]);
				cntZero++;
				idx--;
				idxVec += 2;
			}
			else {
				board[idx][i] = v[idxVec];
				idx--;
				idxVec++;
			}
		}
		if (idxVec == v.size() - 1)board[idx][i] = v[idxVec];
		for (int j = 0; j < cntZero; j++) {
			board[j][i] = 0;
		}
	}
}

bool same(int tmp[20][20]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tmp[i][j] != board[i][j]) return false;
	return true;
}

void dfs(int cnt) {
	/*cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/

	int max_value = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			max_value = max(max_value, board[i][j]);

	if (max_value <= branch_cut[cnt]) return;
	if (cnt == 10) {
		ans = max(ans, max_value);
		int temp = ans;
		while (cnt > 0) {
			branch_cut[cnt--] = temp;
			temp /= 2;
		}
		return;
	}

	int temp[20][20]; // 초기상태 저장
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = board[i][j];

	for (int dir = 0; dir < 4; dir++) {
		switch (dir) {
		case 0:
			left();
			break;
		case 1:
			right();
			break;
		case 2:
			up();
			break;
		case 3:
			down();
			break;
		}
		if (same(temp)) continue; // 이동했는데 이전과 같은경우 탐색안함
		dfs(cnt + 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = temp[i][j];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			ans = max(ans, num);
			board[i][j] = num;
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}