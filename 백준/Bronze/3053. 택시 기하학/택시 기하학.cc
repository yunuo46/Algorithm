#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX 20
#define PI 3.1415926535897932
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	double r;
	cin >> r;

	cout << fixed;
	cout.precision(6);
	cout << r * r * PI << "\n" << 2 * r * r << "\n";
    return 0;
}