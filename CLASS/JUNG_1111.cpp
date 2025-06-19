// 1111 등산로 찾기

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int mount[102][102];
int cost[102][102];

//경계를 0으로 채우고 1,1부터 시작

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<102; i++) {
        fill(mount[i], mount[i]+102, 0);
        fill(cost[i], cost[i]+102, INT_MAX);
    }

    int n, topx, topy;
    cin >> n >> topx >> topy;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> mount[i][j];
        }
    }

    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=n+1; j++) {
            cout << mount[i][j] << " ";
        }
        cout << "\n";
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    queue<pair<int, int> > q;
    q.push(make_pair(topx, topy));
    cost[topx][topy] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if (x < 0 || x > 101 || y < 0 || y > 101) continue;

            int temp = mount[x][y] - mount[cur.first][cur.second];
            if (temp < 0) temp = temp  * temp;

            int newCost = cost[cur.first][cur.second] + temp;
            if (newCost < cost[x][y]) {
                cost[x][y] = newCost;
                q.push(make_pair(x, y));
            }

        }
    }

    cout << "\n";
    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=n+1; j++) {
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }

    // int minCost = INT_MAX;
    // for (int i=0; i<=n+1; i++) {
    //     minCost = min(minCost, cost[0][i]);
    // }
    // for (int i=0; i<=n+1; i++) {
    //     minCost = min(minCost, cost[n+1][i]);
    // }
    // for (int i=0; i<=n+1; i++) {
    //     minCost = min(minCost, cost[i][0]);
    // }
    // for (int i=0; i<=n+1; i++) {
    //     minCost = min(minCost, cost[i][n+1]);
    // }

    int minCost = cost[0][0];
    cout << minCost << "\n";

    return 0;
}