#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

pair<int, int> operator +(const std::pair<int, int>& x, const std::pair<int, int>& y) {
    return std::make_pair(x.first + y.first, x.second + y.second);
}

int n, m, ans = 11;
char c;
bool board[23][23] = { false };
vector<pair<int,int>> coin;
pair<int, int> d[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int clear(pair<int, int> next[2]) {
    bool a = false;
    bool b = false;
    if (next[0].first<1 || next[0].first>n || next[0].second<1 || next[0].second>m) {
        a = true;
    }
    if (next[1].first<1 || next[1].first>n || next[1].second<1 || next[1].second>m) {
        b = true;
    }
    //cout << "a:" << a << "b:" << b << endl;
    if (!a && !b) return 1; // 둘 다 떨어지지 않은 경우
    else if (a || b) {
        if (a && b) return 2; // 둘 다 떨어진 경우
        else return 3; // 한쪽만 떨어진 경우 (clear)
    }
}

bool is_wall(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m && !board[x][y]) return true;
    else return false;
}

void bfs(pair<int,int> now[2], int cnt) {
    //cout << "cnt"<<cnt << endl;
    if (cnt > 10) return;
    //cout << now[1].first << "," << now[1].second << endl;
    for (int i = 0; i < 4; i++) {
        pair<int, int> next[2] = { {now[0] + d[i]},{now[1] + d[i]} };
        //cout << next[0].first << "," <<next[0].second << endl;
        if (is_wall(next[0].first, next[0].second)) next[0] = now[0];
        if (is_wall(next[1].first, next[1].second)) next[1] = now[1];
        int type = clear(next);
        //cout << "type" << type << endl;
        if (type == 1)bfs(next, cnt + 1);
        else if (type == 2) continue;
        else {
            ans = min(ans, cnt);
        }
    }
    
}

int32_t main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c != '#') board[i][j] = true;
            if (c == 'o') {
                coin.push_back({ i,j });
            }
        }
    }
    pair<int, int> now[2] = { coin[0],coin[1]};
    bfs(now, 1);
    if (ans == 11) ans = -1;
    cout << ans;
}