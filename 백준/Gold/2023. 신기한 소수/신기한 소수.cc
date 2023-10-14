#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> sol;

int check(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void dfs(int now, int num) {
    int flag;
    int temp;

    if (now == n) {
        sol.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        temp = num * 10;
        temp += i;
        flag = check(temp);
        if (flag == 0)
            continue;

        dfs(now + 1, temp);
    }
}

int main(void) {

    cin >> n;

    dfs(1, 2);
    dfs(1, 3);
    dfs(1, 5);
    dfs(1, 7);

    sort(sol.begin(), sol.end());

    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << endl;
}