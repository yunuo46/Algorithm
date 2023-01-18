#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, m, pos, ans = 0;
string s;
bool state = false;
queue<char> q;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string cmp = "I";
    while (n--) cmp.append("OI");
    cin.ignore();
    getline(cin, s);
    pos = 0;
    while (pos != -1) {
        pos = s.find(cmp, pos+1);
        ans++;
    }
    cout << ans - 1;
    return 0;
}