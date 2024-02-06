#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n;
stack<int> s;
vector<int> ans;
int arr[1000001];

int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ans.push_back(-1);
    for (int i = n-1; i >= 1; i--) {
        if (arr[i + 1] > arr[i]) {
            s.push(arr[i + 1]);
            ans.push_back(arr[i + 1]);
        }
        else {
            while (!s.empty() && arr[i] >= s.top()) s.pop();
            if (s.empty()) ans.push_back(-1);
            else {
                ans.push_back(s.top());
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}