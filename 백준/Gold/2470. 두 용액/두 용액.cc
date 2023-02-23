#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> v;
int n, num, l, r;
pair<pair<int, int>, int> ans;

void TwoPointer() {
	l = 0, r = n - 1;
	int sum = v[l] + v[r];
	ans = { {l,r },abs(sum) };
	while (l < r) {
		if (sum == 0) {
			ans = { {l,r},sum };
			break;
		}
		else if (sum < 0) {
			if (abs(sum) < ans.second) ans = { {l,r},abs(sum) };
			l++;
		}
		else {
			if (abs(sum) < ans.second) ans = { {l,r},abs(sum) };
			r--;
		}
		sum = v[l] + v[r];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	TwoPointer();
	cout << v[ans.first.first] << " " << v[ans.first.second];
	return 0;
}