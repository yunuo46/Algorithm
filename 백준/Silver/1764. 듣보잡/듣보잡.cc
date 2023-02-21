#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map <string, int> h;
vector <string> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        h[s]++;
    }
    while (m--) {
        string s;
        cin >> s;
        h[s]++;
        if (h[s] > 1) v.push_back(s);
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}