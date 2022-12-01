#include <bits/stdc++.h>
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
#define endl "\n"
using namespace std;
int N;
int col[32][26] = { 0 }, row[26] = { 0 }, dia1[64][26] = { 0 }, dia2[64][26] = { 0 };
char board[32][32] = { '.' };
char ans = 'f';

int32_t main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];

			if (board[i][j] == '.') continue;

			if (board[i - 1][j] == board[i][j]) col[j][board[i][j] - 'A']++;
			else col[j][board[i][j] - 'A'] = 0;

			if(board[i][j-1] == board[i][j]) row[board[i][j] - 'A']++;
			else row[board[i][j] - 'A'] = 0;

			if (board[i - 1][j-1] == board[i][j]) dia1[31+i-j][board[i][j] - 'A']++;
			else dia1[31+i-j][board[i][j] - 'A'] = 0;

			if (board[i - 1][j + 1] == board[i][j]) dia2[i+j][board[i][j] - 'A']++;
			else dia2[i + j][board[i][j] - 'A'] = 0;

			if (board[i][j] != '.' && (col[j][board[i][j] - 'A'] >= 2 || row[board[i][j] - 'A'] >= 2 || dia1[31 + i - j][board[i][j] - 'A'] >= 2 || dia2[i + j][board[i][j] - 'A'] >= 2)) ans = board[i][j];
		}
	}
	if (ans == 'f') cout << "ongoing";
	else cout << ans;
	
	return 0;
}