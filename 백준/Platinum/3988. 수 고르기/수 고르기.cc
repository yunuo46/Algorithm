#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, k, num, ans = INT_MAX;
vector<int> v;
vector<int> dif;
deque<int> dq;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end()); 

	for (int i = 1; i < n; i++) dif.push_back(v[i] - v[i - 1]);

	int len = n - k - 1;

	for (int i = 0; i < n - 1; i++) {
		if (i >= len)
			if (!dq.empty() && dq.front() <= i-len)
				dq.pop_front();
		// i이전 삭제, len만큼 탐색
		while (!dq.empty() && dif[i] <= dif[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
		if (i >= len-1) ans = min(ans, v[i+1]-v[i-len+1] + dif[dq.front()]);
	}
	cout << ans;
	return 0;
}