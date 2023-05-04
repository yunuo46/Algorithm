#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, k, ans, tmp = 0;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	bitset<51> bt(n);
	int sz = 0;
	for (int i = 0; i < 50; i++)
		if (bt[i] == 1)
			sz = i;
	sz++;
	if (k == 1) {
		ans = n;
	}
	else if (k < sz) {
		ans = (k - 1) + (pow(2, (sz - k)) - 1);
		int x = pow(2, (sz - k)) - 1;
		bitset<51> andbit(x);
		bitset<51> t = bt & andbit;
		tmp = t.to_ullong() + 1;
		for (int i = sz - 1; i >= sz - k; i--) {
			if (bt[i] == 0) tmp = 0;
		}
	}
	else {
		ans = sz - 1;
		if (bt.count() == sz) ans++;
	}
	cout << ans + tmp;
	return 0;
}