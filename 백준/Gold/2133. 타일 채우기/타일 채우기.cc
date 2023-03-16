#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 500001
using namespace std;

int n;
int ans[31];

int dp(int idx) {
	if (ans[idx]) return ans[idx];

	return ans[idx] = dp(idx - 2) * 4 - dp(idx - 4);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}
	ans[2] = 3;
	ans[4] = 11;
	cout << dp(n);
}
