// 7576 토마토

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int tomato[1001][1001];
    int vis[1001][1001];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + m, -1);
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                vis[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if (x < 0 || x >= n || y < 0 || y >= m ) continue;

            if (tomato[x][y] == 0 && vis[x][y] == -1) {
                q.push(make_pair(x, y));
                vis[x][y] = vis[cur.first][cur.second] + 1;
                ans = vis[x][y];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] != -1 && vis[i][j] == -1) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << ans << "\n";
}