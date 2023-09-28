#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m, a, b;
int L[10001], R[10001], A[5001], B[5001];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        A[a]++;
        B[b]++;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            L[i + j] += A[i] * A[j];
            R[i + j] += B[i] * B[j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * m; i++) {
        ans += L[i];
        cout << ans << endl;
        ans -= R[i];
    }
    return 0;
}
