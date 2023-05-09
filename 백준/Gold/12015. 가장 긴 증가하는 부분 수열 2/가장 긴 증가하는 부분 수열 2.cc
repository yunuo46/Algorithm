#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include<cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#define endl "\n"
using namespace std;

int arr[1000001];
vector<int> sequence;
int n;

void binary_search(int num) {
    int low = 0, high = sequence.size() - 1, mid;
    int ret = 1000000007;
    while (low <= high) {
        mid = (low + high) / 2;
        int here_num = sequence[mid];
        if (here_num >= num) {
            if (ret > mid)
                ret = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    sequence[ret] = num;
}

void find_lis() {
    sequence.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (sequence.back() < arr[i]) {
            sequence.push_back(arr[i]);
        }
        else {
            binary_search(arr[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    find_lis();
    cout << sequence.size();

    return 0;
}