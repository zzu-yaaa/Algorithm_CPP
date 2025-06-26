// 15650 N과 N (2)

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans;

void func(int num) {
    if (ans.size() == m) {
        for (int temp : ans) {
            cout << temp << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = num; i<=n; i++) {
        ans.push_back(i);
        func(i+1);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(1);

    return 0;
}