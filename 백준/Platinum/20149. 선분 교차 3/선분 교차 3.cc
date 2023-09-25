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
	bool operator==(P const& p1) {
		if (x == p1.x) {
			return y == p1.y;
		}
		return false;
	}
};

struct Line {
	P p1, p2;
};

Line L[3001];

int32_t ccw(const P& p1, const P& p2, const P& p3) {
	int temp = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
		(p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

bool cross(int a, int b) {
	int c1 = ccw(L[a].p1, L[a].p2, L[b].p1) * ccw(L[a].p1, L[a].p2, L[b].p2);
	int c2 = ccw(L[b].p1, L[b].p2, L[a].p1) * ccw(L[b].p1, L[b].p2, L[a].p2);


	if (c1 <= 0 && c2 <= 0) {
		if (c1 == 0 && c2 == 0) {
			if (L[a].p2 <= L[a].p1) swap(L[a].p1, L[a].p2);
			if (L[b].p2 <= L[b].p1) swap(L[b].p1, L[b].p2);

			if (L[a].p1 <= L[b].p2 && L[b].p1 <= L[a].p2) return true;
			else return false;
		}
		else return true;
	}
	else return false;
}

void sol(P& p1, P& p2, P& p3, P& p4) {
	double px = (p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x);
	double py = (p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x);
	double p = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

	if (p == 0){
		if (p2 == p3 && p1 <= p3) cout << p2.x << " " << p2.y << endl;
		else if (p1 == p4 && p3 <= p1) cout << p1.x << " " << p1.y << endl;
	}
	else
	{
		double x = px / p;
		double y = py / p;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	P p1, p2;
	for (int i = 0; i < 2; i++) {
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		L[i].p1 = p1;
		L[i].p2 = p2;
	}

	if (cross(0, 1)) {
		cout << 1 << endl;
		sol(L[0].p1, L[0].p2, L[1].p1, L[1].p2);
	}
	else cout << 0;
	
	return 0;
}
