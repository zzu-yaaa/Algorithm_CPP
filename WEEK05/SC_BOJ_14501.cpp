// 14501 퇴사

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[25];
    fill(arr, arr+25, 0);
    int t[25];
    int p[25];
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        //cout << i << " " << t[i] << " " << p[i] << "\n";
    }

    for (int i=n; i>0; i--) {
        if (i + t[i] - 1 > n) {
            arr[i] = arr[i+1];
        }
        else {
            arr[i] = max(arr[i+1], arr[i+t[i]] + p[i]);
        }
        //cout << n << " " << arr[i] << "\n";
    }
    cout << arr[1] << "\n";

    return 0;
}