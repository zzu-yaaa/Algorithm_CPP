// 11780 플로이드2

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000001
int graph[101][101];
int nxt[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    for (int i=0; i<=n; i++) {
        fill(graph[i], graph[i]+n+1, INF);
    }

    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b],c);
        nxt[a][b] = b;
    }

    for (int i=1; i<=n; i++) {
        graph[i][i] = 0;
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (graph[i][j] == INF) graph[i][j] = 0;
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    vector<int> v;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (graph[i][j] == 0) {
                cout << "0\n";
                continue;
            }

            int cur = i;
            v.push_back(cur);
            while (cur != j) {
                v.push_back(nxt[cur][j]);
                cur = nxt[cur][j];
            }

            cout << v.size() << " ";
            for (int temp : v) {
                cout << temp << " ";
            }
            cout << "\n";
            v.clear();
        }

    }

    return 0;
}