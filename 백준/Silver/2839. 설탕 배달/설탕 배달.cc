#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n;

int32_t grid(int w) {
	int w_5 = w / 5;
	int tmp = 0;

	while (w_5 >= 0) {
		tmp = w - (5 * w_5);
		if (tmp % 3 == 0)return w_5 + tmp / 3;
		w_5 -= 1;
	}
	return -1;
}


int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	cout << grid(n) << endl;
}