#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int m[1000001];
int n, num, ans = 0;

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> num;
		if (m[num]) {
			m[num]--;
			m[num - 1]++;
		}
		else {
			m[num - 1]++;
			ans++;
		}
	}
	cout << ans;
}