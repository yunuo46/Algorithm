#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> v;
int n, num, sum, ans = 0;

void TwoPointer() {
	int l = 0, r = 1;
	int temp = v[l];
	while (l < n) {
		if (temp == (sum-temp)) {
			ans = temp;
			break;
		}
		else if (temp < (sum - temp)) {
			ans = max(ans, min(temp, sum - temp));
			temp += v[r++];
			r %= n;
		}
		else temp -= v[l++];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		sum += num;
	}
	TwoPointer();
	cout << ans;
	return 0;
}