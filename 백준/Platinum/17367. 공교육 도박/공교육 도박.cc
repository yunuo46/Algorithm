#include<bits/stdc++.h>
using namespace std;

double arr[7][7][7][1001];

double score(int x1, int x2, int x3) {
    if (x1 == x2 && x2 == x3) {
        return 10000 + x1 * 1000;
    }
    else if (x1 == x2 && x2 != x3) {
        return 1000 + x1 * 100;
    }
    else if (x1 == x3 && x3 != x2) {
        return 1000 + x1 * 100;
    }
    else if (x2 == x3 && x2 != x1) {
        return 1000 + x2 * 100;
    }
    else {
        return max({ x1, x2, x3 }) * 100;
    }
}

double dp(int x1, int x2, int x3, int n) {
    if (arr[x1][x2][x3][n] != 0) {
        return arr[x1][x2][x3][n];
    }
    if (n == 3) {
        return arr[x1][x2][x3][n] = score(x1, x2, x3);
    }

    double sum = 0;
    for (int i = 1; i <= 6; i++) {
        sum += dp(i, x1, x2, n - 1);
    }
    sum /= 6.0;
    
    return arr[x1][x2][x3][n] = max(score(x1, x2, x3), sum);
}

int main() {
    int n;
    cin >> n;

    double ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                ans += dp(i, j, k, n);
            }
        }
    }
    ans /= (6.0 * 6.0 * 6.0);
    cout << fixed << ans;
}