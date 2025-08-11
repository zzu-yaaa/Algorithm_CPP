// 17835 면접보는 승범이네

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, u, v, c;
    cin >> n >> m >> k;

    int graph[n+1][n+1];
    for (int i=0; i<n+1; i++) {
        fill(graph[i], graph[i]+n+1, INF);
    }

    for (int i=0; i<m; i++) {
        cin >> u >> v >> c;
        if (graph[u][v] > c) graph[u][v] = c;
    }

    for (int i=1; i<=n; i++) {
        graph[i][i] = 0;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << graph[i][j] << " ";
        }
        cout <<"\n";
    }

    cout << "---------------------\n";

    for (int z=1; z<=n; z++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (graph[i][j] > graph[i][z] + graph[z][j]) {
                    graph[i][j] = graph[i][z] + graph[z][j];
                }
            }
        }
    }

    vector<int> city;
    int temp;
    int maxVal = -1;

    for (int i=0; i<k; i++) {
        cin >> temp;
        city.push_back(temp);
        for (int j=1; j<=n; j++) {
            if (graph[j][temp] == INF) continue;
            maxVal = max(maxVal, graph[j][temp]);
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << graph[i][j] << " ";
        }
        cout <<"\n";
    }

    int ans = 100001;
    for (int c : city) {
        for (int i=1; i<=n; i++) {
            if (graph[i][c] == maxVal) {
                ans = min(ans, i);
            }
        }
    }

    cout << ans << "\n" << maxVal << "\n";

    return 0;
}