// 4179 불

#include <iostream>
#include <queue>
using namespace std;

char maze[1002][1002] = {0};
int fire[1002][1002];
int jihoon[1002][1002];

int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};

int main() {
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        fill(fire[i], fire[i] + c, -1);
        fill(jihoon[i], jihoon[i] + c, -1);
    }

    queue<pair<int, int> > q;
    pair<int, int> temp;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'F') {
                q.push(make_pair(i, j));
                fire[i][j] = 0;
            }
            else if (maze[i][j] == 'J') {
                temp.first = i;
                temp.second = j;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if (x < 0 || x >= r || y < 0 || y >= c) continue;

            if (maze[x][y] != '#' && fire[x][y] == =1) {
                q.push(make_pair(x, y));
                fire[x][y] = fire[cur.first][cur.second] + 1;
            }
        }
    }

    q.push(temp);
    jihoon[temp.first][temp.second] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            int second = jihoon[cur.first][cur.second];

            if (x < 0 || x >= r || y < 0 || y >= c) {
                //탈출
                cout << second + 1 << "\n";
                return 0;
            }

            if (maze[x][y] != '#' && jihoon[x][y] == -1){
                if (second+1 < fire[x][y] || fire[x][y] == -1) {
                    q.push(make_pair(x, y));
                    jihoon[x][y] = second + 1;
                }
            }

        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}