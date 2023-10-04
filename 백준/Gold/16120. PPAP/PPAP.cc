#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#define endl "\n"
using namespace std;

stringstream ss;
char c;
string str;
vector<char> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int i = 0;

    getline(cin, str);
    ss.str(str);
    while (ss >> c) {
        v.push_back(c);
        while (true) {
            i = v.size();
            if (i >= 4) {
                if (v[i - 4] == 'P' && v[i - 3] == 'P' && v[i - 2] == 'A' && v[i - 1] == 'P') {
                    v.pop_back();
                    v.pop_back();
                    v.pop_back();
                    if (i == 1)break;
                }
                else break;
            }
            else break;
        }
    }
    if (i == 1&&v[0]=='P')cout << "PPAP";
    else cout << "NP";
}