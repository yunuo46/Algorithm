#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, s, ans, num;
vector<int> v;

void dfs(int idx, int sum) {
	if (idx == n) return;
	if (sum + v[idx] == s) ans++;

	dfs(idx + 1, sum);
	dfs(idx + 1, sum + v[idx]);
} 

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	dfs(0, 0);
	cout << ans;
}