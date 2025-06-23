// 15655 N과 M (6)

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[9];
int vis[9];
vector<int> ans;

void func(int start) {
    if (ans.size() == m) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++) {
        if (vis[i] == 1) continue;

        ans.push_back(arr[i]);
        vis[i] = 1;
        func(i+1);
        ans.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(arr, arr+9, 0);
    fill(vis, vis+9, 0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    func(0);

    return 0;
}