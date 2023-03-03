#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m, num;
vector<int>arr;

int32_t binary_search(int num) {
	int l = 0;
	int r = arr.size()-1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] == num)return 1;
		else if (arr[m] > num) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << binary_search(num)<<" ";
	}
	return 0;
}