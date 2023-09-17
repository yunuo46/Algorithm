#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, k, num, u, d,ans;
vector<int> v;
deque<int> dq;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> u >> d;
		d = -d;
		while (!dq.empty() && u >= abs(dq.back())) {
			dq.pop_back();
		}
		dq.push_back(u);
		while (!dq.empty() && abs(d) >= abs(dq.back())) {
			dq.pop_back();
		}
		dq.push_back(d);
	}
	//for (int i = 0; i < dq.size(); i++) cout << dq[i] << " ";

	vector<int> ans(v.size());
	copy(v.begin(), v.end(), ans.begin());
	sort(v.begin(), v.begin() + abs(dq[0]));

	int midx = 0;
	int Midx = abs(dq[0]) - 1;
	int from, to;
	for (int i = 0; i < dq.size(); i++) {
		from = abs(dq[i]) - 1;
		if (i == dq.size() - 1) to = -1;
		else to = abs(dq[i + 1]) - 1;
		if (dq[i] > 0) {
			while (from > to) {
				ans[from] = v[Midx];
				Midx--;
				from--;
			}
		}
		else {
			while (from > to) {
				ans[from] = v[midx];
				midx++;
				from--;
			}
		}
		/*for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << endl;*/
	}
	//cout << Midx << " " << midx << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}