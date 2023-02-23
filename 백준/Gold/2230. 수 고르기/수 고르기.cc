#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> v;
int n,m, num, l, r;
int ans, dif;

void TwoPointer() {
	l = 0, r = 0;
	while (l < n && r < n) {
		dif = v[r] - v[l] - m;
		if (dif == 0) {
			ans = 0;
			break;
		}
		else if (dif < 0) {
			r++;
		}
		else {
			if (dif < ans) ans = dif;
			l++;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	ans = v[n - 1] - v[0] - m;
	TwoPointer();
	cout << ans + m;
	return 0;
}