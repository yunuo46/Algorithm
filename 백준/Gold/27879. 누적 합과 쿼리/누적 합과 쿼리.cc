#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, q, ans;
int markR[1001][1001][4] = { 0 };
int markC[1001][1001][4] = { 0 };
int markSR[1001][1001][4] = { 0 };
int markSC[1001][1001][4] = { 0 };
char** arr;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			string temp;
			temp += arr[i][j - 1];
			temp += arr[i][j];
			markR[i][j][0] = markR[i][j - 1][0];
			markR[i][j][1] = markR[i][j - 1][1];
			markR[i][j][2] = markR[i][j - 1][2];
			markR[i][j][3] = markR[i][j - 1][3];
			if (temp == "aa") {
				markR[i][j][0]++;
			}
			else if (temp == "ab") {
				markR[i][j][1]++;
			}
			else if (temp == "ba") {
				markR[i][j][2]++;
			}
			else {
				markR[i][j][3]++;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			string temp;
			temp += arr[i - 1][j];
			temp += arr[i][j];
			markC[i][j][0] = markC[i - 1][j][0];
			markC[i][j][1] = markC[i - 1][j][1];
			markC[i][j][2] = markC[i - 1][j][2];
			markC[i][j][3] = markC[i - 1][j][3];
			if (temp == "aa") {
				markC[i][j][0]++;
			}
			else if (temp == "ab") {
				markC[i][j][1]++;
			}
			else if (temp == "ba") {
				markC[i][j][2]++;
			}
			else {
				markC[i][j][3]++;
			}
		}
	}
	for (int i = 1; i < n; i++)
		for (int k = 0; k < 4; k++) {
			markSR[0][i][k] = markR[0][i][k];
			markSC[i][0][k] = markC[i][0][k];
		}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			for (int k = 0; k < 4; k++) {
				markSR[i][j][k] = markSR[i - 1][j][k] + markR[i][j][k];
				markSC[i][j][k] = markSC[i][j - 1][k] + markC[i][j][k];
			}

	// 누적합 계산
	//cout << markSR[4][4][0] << " " << markSC[4][4][0] << endl;

	cin >> q;
	int i1, i2, j1, j2;
	string s;
	int ans;
	for (int i = 0; i < q; i++) {
		cin >> i1 >> j1 >> i2 >> j2 >> s;
		i1 -= 1;
		j1 -= 1;
		i2 -= 1;
		j2 -= 1;

		ans = 0;
		int k;
		if (s == "aa") k = 0;
		else if (s == "ab")k = 1;
		else if (s == "ba")k = 2;
		else k = 3;
		ans += markSR[i2][j2][k];
		ans += markSC[i2][j2][k];
		//cout << ans << " ";
		ans -= markSC[i1][j2][k];
		ans -= markSR[i2][j1][k];
		//cout << ans << " ";
		if(i1>0) ans -= (markSR[i1 - 1][j2][k] - markSR[i1 - 1][j1][k]);
		if(j1>0) ans -= (markSC[i2][j1-1][k]-markSC[i1][j1-1][k]);
		cout << ans << endl;
	}
	return 0;
}