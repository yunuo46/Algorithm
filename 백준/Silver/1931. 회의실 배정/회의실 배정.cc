#include <bits/stdc++.h>
#define int long long
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
#define endl "\n"
using namespace std;
int N, s, e, ans = 1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int32_t main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		pq.push({ e,s });
	}
	int back = pq.top().first;
	pq.pop();
	int front = pq.top().second;
	while (!pq.empty()) {
		if (front >= back) {
			ans++;
			back = pq.top().first;
			pq.pop();
			if(!pq.empty()) front = pq.top().second;
		}
		else {
			pq.pop();
			if (!pq.empty()) front = pq.top().second;
		}
	}
	cout << ans;
	return 0;
}