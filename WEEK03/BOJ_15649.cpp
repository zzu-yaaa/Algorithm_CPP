// 15649 N과 M(1)
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int vis[9];
vector<int> ans;

void func() {
    if (ans.size() == m) {
        for (int i=0; i<m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=n; i++) {
        if (vis[i] == 1) continue;

        ans.push_back(i);
        vis[i] = 1;
        func();
        ans.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func();

    return 0;
}