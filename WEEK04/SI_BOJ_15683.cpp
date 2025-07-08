// 15683 감시

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int office[9][9];
vector<vector<int> > v;
int ans = INT_MAX;

// void up(int x, int y, int val) {
//     for (int i=0; i<x; i++) {
//         if (office[i][y] == 6) break;
//         if (office[i][y] == 0) office[i][y] = val;
//     }
// }

void up(int x, int y, int val, int vis[][9]) {
    if (val == -1) {
        for (int i=x-1; i>=0; i--) {
            if (office[i][y] == 6) break;
            if (office[i][y] == 0) {
                office[i][y] = val;
                vis[i][y] = 1;
            }
        }
    }
    else if (val == 0) {
        for (int i=x-1; i>=0; i--) {
            if (office[i][y] == 6) break;
            if (vis[i][y] == 1 && office[i][y] == -1) {
                office[i][y] = val;
                vis[i][y] = 0;
            }
        }
    }
}

void down(int x, int y, int val, int vis[][9]) {
    if (val == -1) {
        for (int i=x+1; i<n; i++) {
            if (office[i][y] == 6) break;
            if (office[i][y] == 0) {
                office[i][y] = val;
                vis[i][y] = 1;
            }
        }
    }
    else if (val == 0) {
        for (int i=x+1; i<n; i++) {
            if (office[i][y] == 6) break;
            if (vis[i][y] == 1 && office[i][y] == -1) {
                office[i][y] = val;
                vis[i][y] = 0;
            }
        }
    }
}

void left(int x, int y, int val, int vis[][9]) {
    if (val == -1) {
        for (int i=y-1; i>=0; i--) {
            if (office[x][i] == 6) break;
            if (office[x][i] == 0) {
                office[x][i] = val;
                vis[x][i] = 1;
            }
        }
    }
    else if (val == 0) {
        for (int i=y-1; i>=0; i--) {
            if (office[x][i] == 6) break;
            if (vis[x][i] == 1 && office[x][i] == -1) {
                office[x][i] = val;
                vis[x][i] = 0;
            }
        }
    }
}

void right2(int x, int y, int val, int vis[][9]) {
    if (val == -1) {
        for (int i=y+1; i<m; i++) {
            if (office[x][i] == 6) break;
            if (office[x][i] == 0) {
                office[x][i] = val;
                vis[x][i] = 1;
            }
        }
    }
    else if (val == 0) {
        for (int i=y+1; i<m; i++) {
            if (office[x][i] == 6) break;
            if (vis[x][i] == 1 && office[x][i] == -1) {
                office[x][i] = val;
                vis[x][i] = 0;
            }
        }
    }
}

void func(int idx) {
    if (idx == v.size()) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << office[i][j] << " ";
                if (office[i][j] == 0) cnt++;
            }
            cout << "\n";
        }
        cout << "-------------------------\n";

        ans = min(ans, cnt);
        return;
    }

    int cctv = v[idx][0];
    int x = v[idx][1];
    int y = v[idx][2];
    int vis[9][9];
    for (int i=0; i<9; i++) {
        fill(vis[i], vis[i]+9, 0);
    }

    switch (cctv) {
        case 1:
            for (int i=0; i<4; i++) {
                if (i==0) {
                    up(x, y, -1, vis);
                    func(idx+1);
                    up(x, y, 5, vis);
                }
                else if (i==1) {
                    down(x, y, -1, vis);
                    func(idx+1);
                    down(x,y,0, vis);
                }
                else if (i==2) {
                    left(x, y, -1, vis);
                    func(idx+1);
                    left(x,y,0, vis);
                }
                else if (i==3) {
                    right2(x, y, -1, vis);
                    func(idx+1);
                    right2(x, y, 0, vis);
                }
            }
            break;
        case 2:
            for (int i=0; i<2; i++) {
                if (i==0) {
                    up(x, y, -1, vis);
                    down(x, y, -1, vis);
                    func(idx+1);
                    up(x, y, 0, vis);
                    down(x,y,0, vis);
                }
                else if (i==1) {
                    left(x, y, -1, vis);
                    right2(x, y, -1, vis);
                    func(idx+1);
                    left(x,y,0, vis);
                    right2(x, y, 0, vis);
                }
            }
            break;
        case 3:
            for (int i=0; i<4; i++) {
                if (i==0) {
                    down(x, y, -1, vis);
                    left(x, y, -1, vis);
                    func(idx+1);
                    down(x,y,0, vis);
                    left(x,y,0, vis);
                }
                else if (i==1) {
                    down(x, y, -1, vis);
                    right2(x, y, -1, vis);
                    func(idx+1);
                    down(x,y,0, vis);
                    right2(x, y, 0, vis);
                }
                else if (i==2) {
                    up(x, y, -1, vis);
                    left(x, y, -1, vis);
                    func(idx+1);
                    up(x, y, 0, vis);
                    left(x,y,0, vis);
                }
                else if (i==3) {
                    up(x, y, -1, vis);
                    right2(x, y, -1, vis);
                    func(idx+1);
                    up(x, y, 0, vis);
                    right2(x, y, 0, vis);
                }
            }
            break;
        case 4:
            for (int i=0; i<4; i++) {
                if (i==0) {
                    up(x, y, -1, vis);
                    down(x, y, -1, vis);
                    left(x, y, -1, vis);
                    func(idx+1);
                    up(x, y, 0, vis);
                    down(x,y,0, vis);
                    left(x,y,0, vis);
                }
                else if (i==1) {
                    up(x, y, -1, vis);
                    down(x, y, -1, vis);
                    right2(x, y, -1, vis);
                    func(idx+1);
                    up(x, y, 0, vis);
                    down(x,y,0, vis);
                    right2(x, y, 0, vis);
                }
                else if (i==2) {
                    left(x, y, -1, vis);
                    right2(x, y, -1, vis);
                    up(x, y, -1, vis);
                    func(idx+1);
                    left(x,y,0, vis);
                    right2(x, y, 0, vis);
                    up(x, y, 0, vis);
                }
                else if (i==3) {
                    left(x, y, -1, vis);
                    right2(x, y, -1, vis);
                    down(x, y, -1, vis);
                    func(idx+1);
                    left(x,y,0, vis);
                    right2(x, y, 0, vis);
                    down(x, y, 0, vis);
                }
            }
            break;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> node;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> office[i][j];
            if (office[i][j] > 0 && office[i][j] < 5) {
                node.push_back(office[i][j]);
                node.push_back(i);
                node.push_back(j);
                v.push_back(node);
                node.clear();
            }
            if (office[i][j] == 5) {
                int vis[9][9];
                up(i, j, -1, vis);
                down(i, j, -1, vis);
                left(i, j, -1, vis);
                right2(i, j, -1, vis);
            }
        }
    }

    func(0);

    cout << ans << "\n";

    return 0;
}