#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#define endl "\n"
using namespace std;

int dp[1002][1002];
vector <int> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int ans = 0;
	string a, b;
	cin >> a >> b;

	a = "0" + a;
	b = "0" + b;

	for (int i = 1; i < (int)b.size(); i++){
		for (int j = 1; j < (int)a.size(); j++){
			if (b[i] == a[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}