#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 20
using namespace std;

int t, n, a, b;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 1;
        map<int, int>m;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            m[a] = b;
        }
        int minb = m[1];
        for (int i = 2; i <= n; i++) {
            if (m[i] < minb) {
                minb = m[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
}