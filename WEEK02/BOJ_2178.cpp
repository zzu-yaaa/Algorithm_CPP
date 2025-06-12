// 2178 미로 탐색

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int maze[102][102];
    int vis[102][102] = {0};
    char ch;

    cin  >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> ch;
            maze[i][j] = ch - '0';
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    queue<pair<int, int> > q;
    q.push(make_pair(1,1));
    vis[1][1] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int k=0; k<4; k++) {
            int x = cur.first + dx[k];
            int y = cur.second + dy[k];

            if (x < 1 || x > n || y < 1 || y > m) continue;

            if (maze[x][y] == 1 && vis[x][y] == 0) {
                q.push(make_pair(x, y));
                vis[x][y] = vis[cur.first][cur.second] + 1;
            }
        }
    }

    cout << vis[n][m] << "\n";

    return 0;
}