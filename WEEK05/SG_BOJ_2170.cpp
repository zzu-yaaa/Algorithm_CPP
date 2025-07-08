// 2170 선 긋기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<long long, long long> > v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long a, b;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());

    // for (int i=0; i<n; i++) {
    //     cout << v[i].first << " " << v[i].second << "\n";
    // }

    long long s = v[0].first;
    long long e = v[0].second;
    long long ans = 0;

    for (int i=0; i<n-1; i++) {
        if (e >= v[i+1].first) {
            if (e < v[i+1].second) e =

                v[i+1].second;
        }
        else {
            ans += (e-s);
            s = v[i+1].first; e = v[i+1].second;
        }
    }
    ans += (e-s);

    cout << ans << "\n";

    return 0;
}
