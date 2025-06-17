// 정올 1695 단지번호붙이기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26];
int vis[26][26];

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

int dfs(int a, int b, int n, int depth) {
    for (int i=0; i<4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];

        if (x < 0 || x >=n || y < 0 || y >= n) continue;

        if (map[x][y] == 1 && vis[x][y] == 0) {
            vis[x][y] = 1;
            depth = dfs(x,y,n, depth+1);
        }
    }

    return depth;
}

int dfs2(int a, int b, int n, int depth) {
    for (int i=0; i<4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];

        if (x < 0 || x >=n || y < 0 || y >= n) continue;

        if (map[x][y] == 1) {
            map[x][y] = -1;
            depth = dfs2(x,y,n, depth+1);
        }

    }

    return depth;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<26; i++) {
        fill(map[i], map[i]+26, 0);
        fill(vis[i], vis[i]+26, 0);
    }

    char ch;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> ch;
            map[i][j] = ch - '0';
        }
    }

    vector<int> area;
    int cnt=0;

    // ========== vis 배열 사용 ============
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         if (map[i][j] == 1 && vis[i][j] == 0) {
    //             vis[i][j] = 1;
    //             area.push_back(dfs(i, j, n, 1));
    //             cnt += 1;
    //         }
    //     }
    // }

    // ========== vis 배열 미사용 ============
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] == 1) {
                map[i][j] = -1;
                area.push_back(dfs2(i, j, n, 1));
                cnt += 1;
            }
        }
    }



    cout << cnt << "\n";
    sort(area.begin(), area.end());
    for (int temp : area) {
        cout << temp << "\n";
    }

    return 0;
}

