// 10816 숫자 카드 2

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500001];
int b[500001];

int binary_search(int target) {
    sort(a, a+n);

    int low = 0;
    int high = n-1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (target == a[mid]) {
            a[mid] = 20000000;
            return 1;
        }

        if (target > a[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return 0;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }

    for (int i=0; i<m; i++) {
        int cnt = 0;
        while (binary_search(b[i]) != 0) {
            cnt++;
        }
        cout << cnt << " ";
    }

    return 0;
}