#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
#define endl "\n"
using namespace std;
int dp[10000001];
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i - a > 0) dp[i] = min(dp[i], dp[i - a - 1] + 1);
        if (i - b > 0)dp[i] = min(dp[i], dp[i - b - 1] + 1);
    }
    cout << dp[n];
}