// 정올 1078 저글링 방사능 오염

#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int vis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, y, x; //열, 행
    int ans = 0;
    cin >> m >> n;

    for (int i=0; i<101; i++) {
        fill(map[i], map[i]+1, 0);
        fill(vis[i], vis[i]+1, 0);
    }

    char ch;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            cin >> ch;
            map[i][j] = ch - '0';
        }
    }

    cin >> y >> x;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    queue<pair<int, int> > q;
    q.push(make_pair(x-1, y-1));
    vis[x-1][y-1] = 3;
    ans = vis[x-1][y-1];

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;

            if (map[nx][ny] == 1 && vis[nx][ny] == 0) {
                vis[nx][ny] =  vis[cur.first][cur.second] + 1;
                ans = vis[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }

    int rest = 0;
    for (int i = 0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 1 && vis[i][j] == 0) {
                rest += 1;
            }
        }
    }

    cout << ans << "\n" << rest << "\n";

    return 0;
}