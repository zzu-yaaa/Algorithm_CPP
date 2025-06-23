// 9663 N-Queen

#include <iostream>
using namespace std;

int n;
int ans = 0;
int col[16];
int d1[30]; //  /
int d2[30]; //  \

void func(int cnt, int x, int y) {
    if (cnt == n) {
        ans ++;
        return;
    }

    int i = x+1;
    for (int j=0; j<n; j++) {
        if (col[j] == 1 || d1[i+j] == 1 || d2[i-j+n-1] == 1) continue;
        if (j == y) continue;
        if (i+j == x+y) continue;
        if (i-x == j-y) continue;

        col[j] = 1;
        d1[i+j] = 1;
        d2[i-j+n-1] = 1;
        func(cnt+1, i, j);
        col[j] = 0;
        d1[i+j] = 0;
        d2[i-j+n-1] = 0;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++) {
        col[i] = 1;
        d1[0+i] = 1;
        d2[0-i+n-1] = 1;
        func(1, 0, i);
        col[i] = 0;
        d1[0+i] = 0;
        d2[0-i+n-1] = 0;
    }

    cout << ans << "\n";

    return 0;
}