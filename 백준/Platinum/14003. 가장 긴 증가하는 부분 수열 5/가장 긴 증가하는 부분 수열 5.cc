#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int arr[1000001];
int pre[1000001];
vector<int> v;
int n, idx, dptmp = 0;
vector<int>::iterator p;
stack<int> s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
        if (v.size() == 0) {
            v.push_back(arr[i]);
            pre[i] = 1;
        }
        else {
            if (v[v.size() - 1] < arr[i]) {
                v.push_back(arr[i]);
                pre[i] = v.size();
            }
            else {
                p = (lower_bound(v.begin(), v.end(), arr[i]));
                *(p) = arr[i];
                pre[i] = p - v.begin() + 1;
            }
        }
        if (pre[i] > dptmp) {
            idx = i;
            dptmp = pre[i];
        }
    }
    cout << v.size();
    s.push(arr[idx]);
    for (int i = idx - 1; i >= 0; i--) {
        if (arr[i] < arr[idx] && pre[i] + 1 == pre[idx]) {
            idx = i;
            s.push(arr[i]);
        }
    }
    cout << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}