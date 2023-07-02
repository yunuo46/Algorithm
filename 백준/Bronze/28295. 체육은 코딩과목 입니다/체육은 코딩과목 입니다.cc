#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, ans = 0;

void swit(int n) {
	switch (n) {
	case 1:
		ans++;
		ans %= 4;
		break;
	case 2:
		ans += 2;
		ans %= 4;
		break;
	case 3:
		ans--;
		if (ans < 0)ans = 3;
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> n;
		swit (n);
	}
	if (ans == 0)cout << "N";
	else if (ans == 1)cout << "E";
	else if(ans == 2)cout << "S";
	else if(ans == 3)cout << "W";
	return 0;
}