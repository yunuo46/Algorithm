#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x1, x2, x3, x4, y1, y2, y3, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int p1 = ccw(x1, y1, x2, y2, x3, y3);
	int p2 = ccw(x1, y1, x2, y2, x4, y4);
	int p3 = ccw(x3, y3, x4, y4, x1, y1);
	int p4 = ccw(x3, y3, x4, y4, x2, y2);

	if (p1*p2 <= 0 && p3*p4 <= 0) {
		if (p1 * p2 == 0 && p3 * p4 == 0) {
            if(x1 != x2){
                if (x3 > x4) {

				swap(x3, x4);

			}

			if (x1 > x2) {

				swap(x1, x2);

			}
			if (x1 <= x4 && x3 <= x2)
			{
				cout << 1;
			}
			else {
				cout << 0;
			}
            }else{
                if (y3 > y4) {
				swap(y3, y4);
			}
			if (y1 > y2) {
				swap(y1, y2);
			}
                if (y1 <= y4 && y3 <= y2)

			{

				cout << 1;

			}

			else {

				cout << 0;

			}
                }
            
		}
		else
		{
			cout << 1;
		}
	}
	else cout << 0;
	return 0;
}
