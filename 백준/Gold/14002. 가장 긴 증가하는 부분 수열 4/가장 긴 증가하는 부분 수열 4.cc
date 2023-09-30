#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#define endl "\n"
using namespace std;

int n, num, last, ans = 0;
vector<int> v;
int dp[1001];
int pre[1001];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
        int dp_max = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[i] > v[j] && dp_max < dp[j]) {
                dp_max = dp[j];
                pre[i] = j+1;
            }
        }
        dp[i] = dp_max + 1;
        if (ans < dp[i]) {
            ans = dp[i];
            last = i+1;
        }
    }
    cout << ans << endl;
    
    vector<int> ansvec;
    while (last) {
        ansvec.push_back(v[last-1]);
        last = pre[last-1];
    }
    for (int i = ansvec.size()-1; i >= 0; i--) {
        cout << ansvec[i] << " ";
    }
}