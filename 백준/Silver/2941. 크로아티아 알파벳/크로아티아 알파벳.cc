#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 500001
using namespace std;

vector<char> v;
char c;
int ans = 0;
string s;
stringstream ss;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	getline(cin, s);
	ss.str(s);
	while (ss >> c) {
		v.push_back(c);
	}
	v.push_back('0');
	v.push_back('0');
	int idx = 0;
	while (idx < v.size() - 2) {
		if (v[idx] == 'd' && v[idx + 1] == 'z' && v[idx + 2] == '=') {
			idx += 3;
			ans++;
		}
		else if (v[idx] == 'c'&& v[idx + 1] == '=') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == 's' && v[idx + 1] == '=') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == 'z' && v[idx + 1] == '=') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == 'c' && v[idx + 1] == '-') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == 'l' && v[idx + 1] == 'j') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == 'n' && v[idx + 1] == 'j') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == 'c' && v[idx + 1] == '-') {
			idx += 2;
			ans++;
		}
		else if (v[idx] == '-') {
			idx += 1;
		}
		else if (v[idx] == '=') {
			idx += 1;
		}
		else {
			idx += 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}