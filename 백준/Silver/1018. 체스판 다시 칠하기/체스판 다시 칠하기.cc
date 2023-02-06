#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<memory>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int m, n,cnt;
char c;
int chess[8][8] = { {1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1}};
vector<vector<int>> arr;
vector<int> line;
vector<int> cntV;

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'W') line.push_back(1);
			else if (c == 'B') line.push_back(0);
		}
		arr.push_back(line);
		line.clear();
		vector<int>().swap(line);
	}
	for (int i = 0; i < m-7; i++) {
		for (int j = 0; j < n-7; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (chess[k][l] == arr[i + k][j + l])cnt++;
				}
			}
			cntV.push_back(cnt);
			cnt = 0;
		}
	}
	sort(cntV.begin(), cntV.end());
	int ans = min(cntV.front(), 64-cntV.back());
	cout << ans;
}