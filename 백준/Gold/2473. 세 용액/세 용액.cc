#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> v;
int n, num, l, r;
pair<pair<pair<int, int>,int>, int> ans;

void TwoPointer(int idx) {
	l = 0, r = n - 1;
	if (idx == l)l++;
	if (idx == r)r--;
	int sum = v[l] + v[r] + v[idx];
	while (l < r) {
		if (sum == 0) {
			ans = { {{l,r},idx},sum };
			break;
		}
		else if (sum < 0) {
			if (abs(sum) < ans.second) ans = { {{l,r},idx},abs(sum) };
			l++;
			if (idx == l)l++;
		}
		else {
			if (abs(sum) < ans.second) ans = { {{l,r},idx},abs(sum) };
			r--;
			if (idx == r)r--;
		}
		sum = v[l] + v[r] + v[idx];
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
	ans = { {{1,2 },0},abs(v[0]+v[1]+v[2])};
	for (int i = 0; i < n; i++) {
		TwoPointer(i);
	}
	vector<int> sol;
	sol.push_back(v[ans.first.first.first]);
	sol.push_back(v[ans.first.first.second]);
	sol.push_back(v[ans.first.second]);
	sort(sol.begin(), sol.end());
	cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;
	return 0;
}