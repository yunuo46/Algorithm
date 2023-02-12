#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 500001
using namespace std;

vector<int> v;
int n, num, ans = 0;

vector<vector<int>> right(vector<vector<int>> board) {
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = n-1; j >= 0; j--) {
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
	return board;
}
vector<vector<int>> left(vector<vector<int>> board) {
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
		for (int j = n-cntZero; j < n; j++) {
			board[i][j] = 0;
		}
	}
	return board;
}
vector<vector<int>> up(vector<vector<int>> board) {
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
	return board;
}
vector<vector<int>> down(vector<vector<int>> board) {
	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = n-1; j >= 0; j--) {
			if (board[j][i]) v.push_back(board[j][i]);
		}
		if (v.empty())continue;
		int cntZero = n - v.size();
		int idx = n-1;
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
	return board;
}

void dfs(int cnt, vector<vector<int>> board) {
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
	if (cnt == 5) return;
	dfs(cnt + 1, right(board));
	dfs(cnt + 1, left(board));
	dfs(cnt + 1, up(board));
	dfs(cnt + 1, down(board));
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			ans = max(ans, num);
			board[i][j] = num;
		}
	}
	dfs(0, board);
	cout << ans;
	return 0;
}