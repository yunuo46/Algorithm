#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, num, ans = INT_MAX;
int i;
int c = 4;
int cnt_l, cnt_r;
vector<int> v;
vector<int> idx;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        vector<int> kadane;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> num;
            if (num) idx.push_back(i);
            v.push_back(num);
        }
        int min_R = n - idx[0];
        int min_L = idx[idx.size() - 1] + 1;
        int min_LR, min_RL;

        if (min_L < min_R) { c = 0; ans = min(ans, min_L); }
        else { c = 1; ans = min(ans, min_R); }

        if (idx.size() >1){
            min_LR = 2 * (idx[0] + 1) + (n - idx[1]);
            if (min_LR < ans) { c = 2; ans = min(ans, min_LR); cnt_l = idx[0] + 1; cnt_r = min_LR - cnt_l; }
            for (int i = 1; i < idx.size()-1; i++) {
                min_LR = 2 * (idx[i] + 1) + (n - idx[i + 1]);
                if (min_LR < ans) { c = 2; ans = min(ans, min_LR); cnt_l = idx[i] + 1; cnt_r = min_LR - cnt_l; }
            }
            min_RL = 2 * (n - idx[idx.size() - 1]) + (idx[idx.size() - 2] + 1);
            if (min_RL < ans) { c = 3; ans = min(ans, min_RL); cnt_r = n - idx[idx.size() - 1]; cnt_l = min_RL - cnt_r; }
            for (int i = 1; i < idx.size()-1; i++) {
                min_RL = 2 * (n - idx[i]) + (idx[i-1] + 1);
                if (min_RL < ans) { c = 3; ans = min(ans, min_RL); cnt_r = n - idx[i]; cnt_l = min_RL - cnt_r; }
            }
        }

        switch (c) {
        case 0:
            cout << ans << endl;
            for (int i = 0; i < ans; i++) {
                cout << "L";
            }
            break;
        case 1:
            cout << ans << endl;
            for (int i = 0; i < min_R; i++) {
                cout << "R";
            }
            break;
        case 2:
            cout << ans << endl;
            for (int i = 0; i < cnt_l; i++) {
                cout << "L";
            }
            for (int i = 0; i < cnt_r; i++) {
                cout << "R";
            }
            break;
        case 3:
            cout << ans << endl;
            for (int i = 0; i < cnt_r; i++) {
                cout << "R";
            }
            for (int i = 0; i < cnt_l; i++) {
                cout << "L";
            }
            break;
        }
    return 0;
}