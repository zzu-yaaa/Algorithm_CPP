// 10845 큐

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    int n, x;
    cin >> n;

    string s;
    queue<int> q;
    for (int i=0; i<n; i++) {
        cin >> s;
        if (s.compare("push") == 0) {
            cin >> x;
            q.push(x);
        }
        else if (s.compare("pop") == 0) {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (s.compare("size") == 0) {
            cout << q.size() << "\n";
        }
        else if (s.compare("empty") == 0) {
            if (!q.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << 1 << "\n";
            }
        }
        else if (s.compare("front") == 0) {
            if (!q.empty()) {
                cout << q.front() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (s.compare("back") == 0) {
            if (!q.empty()) {
                cout << q.back() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}