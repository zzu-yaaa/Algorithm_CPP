// 1409 벽장문의 이동

#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, cnt;
int order[20];
int minCost = INT_MAX;

void dfs(int depth, int a, int b, int cost) {
    if (depth == cnt) {
        minCost = min(minCost, cost);
        return;
    }

    dfs(depth+1, order[depth], b, cost + abs(a-order[depth]));
    dfs(depth+1, a, order[depth], cost + abs(b-order[depth]));

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a>> b >> cnt;
    for (int i=0; i<cnt; i++) {
        cin >> order[i];
    }

    dfs(0, a, b, 0);
    cout << minCost << "\n";

    return 0;
}

