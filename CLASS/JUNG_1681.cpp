// 1681 해밀턴 순환회로

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cost[14][14];
int vis[14];
int minCost = INT_MAX;

void dfs(int now, int cnt, int total) {
    if (cnt == n-1) {
        if (cost[now][0] != 0) { // 회사로 돌아갈 수 있는 경우에만
            minCost = min(minCost, total + cost[now][0]);
        }
        return;
    }

    for (int i=0; i<n; i++) {
        if (vis[i] == 0 && cost[now][i] != 0) {
            vis[i] = 1;
            dfs(i, cnt+1, total + cost[now][i]);
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++) {
        fill(cost[i], cost[i]+14, 0);
    }
    fill(vis, vis+14, 0);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> cost[i][j];
        }
    }

    vis[0] = 1;
    dfs(0,0,0);

    cout << minCost;

    return 0;
}
