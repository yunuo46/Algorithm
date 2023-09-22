#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, maxr,maxc, ans = 0;
int box[105][105]={0};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	ans += 2 * n * m;
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			cin >> box[i][j];
		}
	}
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			ans += max(0, (box[i][j] - box[i - 1][j]));
			ans += max(0, (box[i][j] - box[i + 1][j]));
			ans += max(0, (box[i][j] - box[i][j-1]));
			ans += max(0, (box[i][j] - box[i][j+1]));
		}
	}
	cout << ans;
	return 0;
}