#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

stack<int> s;
int t, n, num, Max, ans;

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		while (n--) {
			cin >> num;
			s.push(num);
		}
		Max = s.top();
		s.pop();
		while (!s.empty()) {
			if (Max < s.top()) Max = s.top();
			else ans += Max - s.top();
			s.pop();
		}
		cout << ans << endl;
	}
}