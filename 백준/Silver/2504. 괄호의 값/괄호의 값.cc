#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 18
using namespace std;
int ans = 0;
int temp = 1;
stack<char> s;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	stringstream ss;
	string str;
	cin >> str;
	ss.str(str);
	char c;
	char last;
	while (ss >> c) {
		if (c == '(') {
			s.push(c);
			temp *= 2;
		}
		else if (c == ')') {
			if (s.empty() || s.top() != '(') {
				ans = 0;
				break;
			}
			else {
				s.pop();
				if (last == '(') ans += temp;
				temp /= 2;
			}
		}
		else if (c == '[') {
			s.push(c);
			temp *= 3;
		}
		else if (c == ']') {
			if (s.empty() || s.top() != '[') {
				ans = 0;
				break;
			}
			else {
				s.pop();
				if (last == '[') ans += temp;
				temp /= 3;
			}
		}
		else {
			ans = 0;
			break;
		}
		last = c;
	}
	if (!s.empty())ans = 0;
	cout << ans;
	return 0;
}
