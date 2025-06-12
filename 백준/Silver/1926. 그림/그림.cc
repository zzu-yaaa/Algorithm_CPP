#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int paper[501][501];
    int vis[501][501];
    int cnt = 0, width = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> paper[i][j];
        }
    }

    queue<pair<int,int> > q;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (paper[i][j] == 1 && vis[i][j] == 0) {
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                int tempWidth = 0;

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    tempWidth += 1;

                    for (int k=0; k<4; k++) {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];

                        if (x <0 || x >= n || y <0 || y >= m) continue;

                        if (paper[x][y] == 1 && vis[x][y] == 0) {
                            q.push(make_pair(x, y));
                            vis[x][y] = 1;
                        }
                    }
                }

                cnt += 1;
                width = max(width, tempWidth);

            }
        }
    }

    cout << cnt << "\n" << width;

    return 0;
}