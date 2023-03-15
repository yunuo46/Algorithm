#include <iostream>
using namespace std;

void change_c(int r, int g, int b, int& c1, int& c2, int& c3);

int main() {

	int n;
	cin >> n;

	int* r = new int[n];
	int* g = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}

	// 입력

	int c1 = r[0];
	int c2 = g[0];
	int c3 = b[0];

	for (int i= 1; i < n; i++) {
		change_c(r[i], g[i],b[i], c1, c2, c3);
	}
	int min = 0;
	if (c1 > c2) {
		if (c2 > c3) min = c3;
		else min = c2;
	}
	else {
		if (c1 > c3) min = c3;
		else min = c1;
	}
	cout << min;
}

void change_c(int r, int g, int b, int& c1, int &c2,int &c3) {
	int k1 = c1;
	int k2 = c2;
	int k3 = c3;
	if (c2 > c3) {
		k1 = r + c3;
	}
	else
		k1 = r + c2;
	if (c1 > c2) {
		k3 = b + c2;
	}
	else
		k3 = b + c1;
	if (c1 > c3) {
		k2 = g + c3;
	}
	else
		k2 = g + c1;
	c1 = k1;
	c2 = k2;
	c3 = k3;
}
