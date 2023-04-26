#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int l, n, k, num, ans = 200001;
int max_k;
vector<int> dist;
vector<int> charge;

bool check(int cap) {
	if (cap < max_k)return false;
	int cnt = 0;
	int tmp = cap;
	for (int i = 0; i < n; i++) {
		//cout << cap << " " << tmp << " " << dist[i] << endl;
		tmp -= dist[i];
		if (tmp < dist[i + 1]) {
			tmp = cap;
			cnt++;
		}
		if (cnt > k)return false;
	}
	return true;
}

void binary_search(int low, int high) {
	if (low > high)	return;
	int mid = (low + high) / 2;
	if (check(mid)) {
		ans = min(ans, mid);
		binary_search(low, mid - 1);
	}
	else
		binary_search(mid + 1, high);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> l >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		charge.push_back(num);
	}
	dist.push_back(charge[0]);
	for (int i = 1; i < n; i++) {
		dist.push_back(charge[i] - charge[i - 1]);
	}
	dist.push_back(l - charge[n - 1]);
	max_k = *max_element(dist.begin(), dist.end());
	binary_search(0, l);
	cout << ans;
	return 0;
}