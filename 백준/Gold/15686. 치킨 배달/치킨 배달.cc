#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m, num, ans = 100000000;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> choice;
bool visited[100];

void dfs(int cnt, int start) {
    if (cnt == m) {
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            int Min = 100000000;
            for (int j = 0; j < choice.size(); j++) {
                int dis = abs(house[i].first - chicken[choice[j]].first)
                    + abs(house[i].second - chicken[choice[j]].second);

                Min = min(dis,Min);
            }
            sum += Min;
        }
       ans = min(ans,sum);
       return;
    }

    for (int i = start; i < chicken.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            choice.push_back(i);
            dfs(cnt+1, i);
            choice.pop_back();
            visited[i] = 0;
        }
    }
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1) house.push_back(make_pair(i, j));
			if (num == 2) chicken.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	cout << ans;
}