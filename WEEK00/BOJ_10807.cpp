// 10807 개수 세기

#include <iostream>
using namespace std;

int main() {
    int n;
    int v;

    cin >> n;

    int arr[n+1];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> v;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == v) {
            cnt += 1;
        }
    }

    cout << cnt << "\n";
    return 0;
}