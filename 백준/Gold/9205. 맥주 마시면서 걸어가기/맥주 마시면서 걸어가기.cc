#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

bool bfs();

int t, n;
int hx, hy, fx, fy;
pair<int, int> m[100];
bool visited[100];

int32_t main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> hx >> hy;
        for (int i = 0; i < n; i++) {
            cin >> m[i].first >> m[i].second;
        }
        cin >> fx >> fy;
        if (bfs()) cout << "happy" << endl;
        else cout << "sad" << endl;

        fill(visited, visited + 100, false);
    }
}

bool bfs() {
    queue<pair<int, int>>q;
    q.push({ hx,hy });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(fx - x) + abs(fy - y) <= 1000) return true;
        for (int i = 0; i < n; i++) {
            if (visited[i])continue;
            if (abs(x - m[i].first) + abs(y - m[i].second) <= 1000) {
                q.push({ m[i].first,m[i].second });
                visited[i] = true;
            }
        }
    }
    return false;
}