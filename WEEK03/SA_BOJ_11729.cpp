// 11729 하노이 탑 이동 순서

#include <iostream>
using namespace std;

void hanoi(int n, int start, int end) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }
    hanoi(n - 1, start, 6-start-end);
    cout << start << " " << end << "\n";
    hanoi(n - 1, 6-start-end, end);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1<<n) -1 << "\n"; // 최소 이동 = 2^n - 1
    hanoi(n, 1, 3);

    return 0;
}