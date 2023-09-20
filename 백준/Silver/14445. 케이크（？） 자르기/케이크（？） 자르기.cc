#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 20
#define PI 3.1415926535897932
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, ans;
    cin >> n;
    if (n < 2)ans = 0;
    else if (n % 2 == 0)ans = n / 2;
    else ans = (n + 1) / 2;
    cout << ans;
    return 0;
}