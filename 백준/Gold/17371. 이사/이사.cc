#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<numeric>
#include<cmath>
using namespace std;

int x, y;
vector<int> coor_x;
vector<int> coor_y;

priority_queue<double> dis[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        cin >> x >> y;
        coor_x.push_back(x);
        coor_y.push_back(y);
    }
    int size = coor_x.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int distance = pow((coor_x[i] - coor_x[j]), 2) + pow((coor_y[i] - coor_y[j]), 2);
            dis[i].push(distance);
        }
    }
    int minindex = 0;
    int min = dis[0].top();
    if (size > 2) {
        for (int i = 1; i < size; i++) {
            if (dis[i].top() < min) {
                min = dis[i].top();
                minindex = i;
            }
        }
    }
    cout << coor_x[minindex] << " " << coor_y[minindex];
}