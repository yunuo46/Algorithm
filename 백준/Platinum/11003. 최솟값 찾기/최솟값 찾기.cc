#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, l, num;
int temp = 5000001;

struct digits {
	int i, num;
};

struct cmp {
	bool operator()(const digits& a, const digits& b) {
		return a.num > b.num;
	}
};

priority_queue<digits, vector<digits>, cmp> pq;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for (int i = 0; i < l; i++) {
		cin >> num;
		pq.push({ i, num });
		cout << pq.top().num << " ";
	}
	for (int i = l; i < n; i++) {
		cin >> num;
		pq.push({ i, num });
		while(pq.top().i <= i - l) pq.pop();
		cout << pq.top().num << " ";
	}
	return 0;
}