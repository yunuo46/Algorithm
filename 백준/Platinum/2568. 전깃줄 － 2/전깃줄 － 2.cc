#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 500001
using namespace std;

int t, a, b, mid, ans = 0;
int Max = 0;
int line[MAX] = { 0 };
int rline[MAX] = { 0 };
vector<int> arr;
int lis[MAX];
stack<pair<int,int>> record;
vector<int> remain;

int binarysearch(int left, int right, int target) {
	while (left < right) {
		mid = (left + right) / 2;
		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		line[a] = b;
		rline[b] = a;
	}
	for (int i = 1; i <= MAX - 1; i++) {
		if (rline[i]) {
			arr.push_back(rline[i]); // 4 2 6 7 9 1 3 10
		}
	}
	lis[0] = arr[0];
	int i = 1;
	int j = 0;
	record.push(make_pair(arr[0], 0));
	//cout << 0 << " ";
	while (i < arr.size()) {
		if (lis[j] < arr[i]) {
			j += 1;
			record.push(make_pair(arr[i], j));
			//cout << j << " ";
			Max = max(Max, j);
			lis[j] = arr[i];
		}
		else {
			int pos = binarysearch(0, j, arr[i]);
			record.push(make_pair(arr[i], pos));
			//cout << pos << " ";
			Max = max(Max, pos);
			lis[pos] = arr[i];
		}
		i += 1; 
	}
	ans = t - j - 1;
	cout << endl <<  ans << endl;

	while (!record.empty()) {
		if (Max == record.top().second) {
			Max--;
		}
		else {
			remain.push_back(record.top().first);
		}
		record.pop();
	}
	sort(remain.begin(), remain.end());
	for (int i = 0; i < ans; i++) {
		cout << remain[i] << endl;
	}
	return 0;
}