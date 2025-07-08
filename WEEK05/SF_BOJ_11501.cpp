// 11501 주식

#include <iostream>
#include <vector>
using namespace std;

int stock[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i=0; i<n; i++) {
            cin >> stock[i];
        }

        int peak = stock[n-1];
        long long ans = 0;
        for (int i=n-2; i>=0; i--) {
            if (peak < stock[i]) {
                peak = stock[i];
            }
            else {
                ans += (peak - stock[i]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
