// 15652 N과 M (4)

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> ans;

void func() {
    if (ans.size() == m) {
        for (int temp : ans) {
            cout << temp << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=n; i++) {
        if (!ans.empty() && ans.back() > i ) continue;

        ans.push_back(i);
        func();
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func();

    return 0;
}