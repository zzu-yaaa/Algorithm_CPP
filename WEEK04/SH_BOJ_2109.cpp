// 2109 순회강연

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int> > v;

    int n, p, d;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p >> d;
        v.push_back(make_pair(d, p));
    }

    sort(v.begin(), v.end(), cmp);

    int last = v[0].first;
    int ans = v[0].second;
    for (int i=1; i<n; i++) {
        //if (last == v[i].first) continue;

        last = v[i].first;
        ans +=  v[i].second;
        cout << v[i].first  << " " << v[i].second << "\n";
    }

    cout << ans << "\n";

    return 0;
}