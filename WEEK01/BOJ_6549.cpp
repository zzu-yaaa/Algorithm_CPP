// 6549 히스토그램에서 가장 큰 직사각형
// 실패 - 플레티넘

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

long long getArea(stack<int> &st, long long area) {
    int cnt = 1;
    while (!st.empty()) {
        area = max(area, (long long)st.top() * cnt++);
        st.pop();
    }
    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height;

    cin >> n;
    while (n != 0) {
        int minHeight = INT_MAX;
        long long area = -1;
        stack<int> st;

        for (int i=0; i<n; i++) {
            cin >> height;
            minHeight = min(minHeight, height);
            if (!st.empty() && st.top() > height) {
                area = getArea(st, area);
            }
            else {
                st.push(height);
            }
        }

        area = getArea(st, area);
        area = max(area, (long long) minHeight * n);

        cout << area << "\n";
        cin >> n;
    }

    return 0;
}

