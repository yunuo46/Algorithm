#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

struct P {
	int x, y;
	bool operator<=(P const& p1) {
		if (x == p1.x) {
			return y <= p1.y;
		}
		return x <= p1.x;
	}
};

struct Line {
	P p1, p2;
};

Line L[3001];
int Node[3001];

int findTopnode(int a) {
	if (Node[a] < 0) return a;
	return Node[a] = findTopnode(Node[a]);
}

bool is_cycle(int a, int b) {
	a = findTopnode(a);
	b = findTopnode(b);
	if (a == b) return true;
	else return false;
}

void Union_node(int a, int b) {
	a = findTopnode(a);
	b = findTopnode(b);

	if (Node[a] > Node[b]) {
		Node[b] += Node[a];
		Node[a] = b;
	}
	else {
		Node[a] += Node[b];
		Node[b] = a;
	}
}

int32_t ccw(const P& p1, const P& p2, const P& p3) {
	int temp = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
		(p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

int32_t sol(int a, int b) {
	int c1 = ccw(L[a].p1, L[a].p2, L[b].p1) * ccw(L[a].p1, L[a].p2, L[b].p2);
	int c2 = ccw(L[b].p1, L[b].p2, L[a].p1) * ccw(L[b].p1, L[b].p2, L[a].p2);


	if (c1 <= 0 && c2 <= 0) {
		if (c1 == 0 && c2 == 0) {
			if (L[a].p2 <= L[a].p1) swap(L[a].p1, L[a].p2);
			if (L[b].p2 <= L[b].p1) swap(L[b].p1, L[b].p2);

			if (L[a].p1 <= L[b].p2 && L[b].p1 <= L[a].p2) return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	P p1, p2;
	for (int i = 0; i < n; i++) {
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		L[i].p1 = p1;
		L[i].p2 = p2;
	}
	memset(Node, -1, sizeof(Node));

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sol(i, j)) {
				if (!is_cycle(i, j)) {
					Union_node(i, j);
				}
			}
		}
	}

	int ans_group = 0;
	int ans_num = 0;

	for (int i = 0; i < n; i++) {
		if (Node[i] < 0) {
			ans_group++;
			ans_num = max(ans_num, abs(Node[i]));
		}
	}

	cout << ans_group << "\n" << ans_num;
	
	return 0;
}
