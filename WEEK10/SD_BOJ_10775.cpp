// 10775 공항

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int g, p, gate;
    cin >> g >> p;

    for (int i=1; i<=g; i++) {
        parent[i] = i;
    }

    int ans = 0;
    bool end = false;
    while (p--) {
        cin >> gate;

        if (end) continue;

        int nxt = find(gate);
        if (nxt == 0) {
            end = true;
            continue;
        }
        parent[nxt] = find(nxt-1);
        ans++;
    }

    cout << ans << "\n";

    return 0;
}