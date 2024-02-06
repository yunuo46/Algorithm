#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, ans = 0;
int t[1001];
int target[1001];
int m[1001];
bool finished = false;

int32_t main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> target[i];
    for (int i = 0; i < n; i++) m[i] = t[i] - target[i];


    while (!finished) {
        finished = true;
        for (int i = 0; i < n; i++) {
            if (!m[i]) continue; // 0이면 패스
            finished = false;
            int M = abs(m[i]);
            for (int j = i + 1; j <= n; j++) {
                if (m[i] * m[j] > 0 && abs(m[j]) < M) M = abs(m[j]);
                else if (m[i] * m[j] <= 0) {
                    ans += M;
                    for (int k = i; k < j; k++) {
                        if (m[k] > 0)m[k] -= M;
                        else m[k] += M;
                    }
                    i = j - 1;
                    break;
                }
            }
        }
    }
    cout << ans;
}
