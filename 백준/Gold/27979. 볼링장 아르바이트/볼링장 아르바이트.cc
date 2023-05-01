#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, num;
vector<int>v;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >>n;
	int ans = n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<int>cp(v);
	sort(cp.begin(), cp.end(),greater<int>());
	int idx = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (cp[idx] == v[i]) {
			ans--;
			idx++;
		}
	}
	cout << ans;
	return 0;
}