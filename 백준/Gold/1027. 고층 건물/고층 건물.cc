#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int h[51], cnt[51]={0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];

	for (int i = 0; i < n; i++) {
		double now = -1000000000;
		for (int j = i+1; j < n; j++) {
			int a = (h[j] - h[i]);
			int b = j - i;
			double next = a * 1.0 / b;
			if (next > now) {
				cnt[i]++; 
				cnt[j]++;
				now = next;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
	cout << ans;

	return 0;
}
