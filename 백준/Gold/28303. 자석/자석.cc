#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 20
using namespace std;

int n, k, ans = INT_MIN;
int e[500001];
int re[500001];
int me[500001];
int rme[500001];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> e[i];  // 25 14 22 13 4
        re[n - 1 - i] = e[i]; // 역순 저장
    }

    // 누적 최솟값 (aj-kj)
    me[0] = e[0];
    rme[0] = re[0];
    for (int i = 1; i < n; i++) {
        me[i] = min(me[i - 1], e[i] - k * i); // 25 12 12 7 -4
        rme[i] = min(rme[i - 1], re[i] - k * i); 
    }

    for (int i = 1; i < n; i++) {
        ans = max(ans, e[i] - k * i - me[i - 1]);
        ans = max(ans, re[i] - k * i - rme[i - 1]);
    }

    cout << ans;

    return 0;
}