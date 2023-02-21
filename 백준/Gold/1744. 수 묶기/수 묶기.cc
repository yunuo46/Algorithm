#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 20
using namespace std;

int n, num, ans;
bool zero = false;
priority_queue<int,vector<int>,greater<int>> neg;
priority_queue<int> pos;

void calculate(int ps, int ns) {
    int n1, n2;
    for (int i = 0; i < ps / 2; i++) {
        n1 = pos.top();
        pos.pop();
        n2 = pos.top();
        pos.pop();
        if (n1 * n2 > n1 + n2) ans += n1 * n2;
        else ans += n1 + n2;
    }
    for (int i = 0; i < ns / 2; i++) {
        n1 = neg.top();
        neg.pop();
        n2 = neg.top();
        neg.pop();
        ans += n1 * n2;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) pos.push(num);
        else if (num == 0)zero = true;
        else neg.push(num);
    }
    int ps = pos.size();
    int ns = neg.size();
    if (zero) {
        if (ps % 2) {
            calculate(ps, ns);
            ans += pos.top();
        }
        else calculate(ps, ns);
    }
    else {
        if (ps % 2 && ns % 2) {
            calculate(ps, ns);
            if (pos.top() * neg.top() > pos.top() + neg.top()) ans += pos.top() * neg.top();
            else ans += pos.top() + neg.top();
        }
        else if (!(ps % 2) && ns % 2) {
            calculate(ps, ns);
            ans += neg.top();
        }
        else if (ps % 2 && !(ns % 2)) {
            calculate(ps, ns);
            ans += pos.top();
        }
        else {
            calculate(ps, ns);
        }
    }
    cout << ans;
}